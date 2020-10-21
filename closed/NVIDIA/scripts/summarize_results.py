#! /usr/bin/env python3
# Copyright (c) 2020, NVIDIA CORPORATION.  All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os, sys
sys.path.insert(0, os.getcwd())

import re
import glob
import argparse
import json

from scripts.utils import Tree, get_system_type

SCENARIO_PERF_RES_RGXS = {
    "Offline":      r"Samples per second: (\d+\.?\d*e?[-+]?\d*)",
    "Server":       r"Scheduled samples per second : (\d+\.?\d*e?[-+]?\d*)",
    "SingleStream": r"90th percentile latency \(ns\) : (\d+\.?\d*e?[-+]?\d*)",
    "MultiStream":  r"Samples per query : (\d+\.?\d*e?[-+]?\d*)",
}

def traverse_results(results_dir):
    perf_glob = os.path.join(results_dir, "**", "performance", "run_*", "mlperf_log_summary.txt")
    perf_run_logs = glob.glob(perf_glob, recursive=True)

    # Sort the logs so we add each run in order
    perf_run_logs = list(sorted(perf_run_logs))

    results_tree = Tree()
    for entry in perf_run_logs:
        parts = entry.split("/")
        # results/<system_id>/<benchmark>/<scenario>/performance/<run id>/mlperf_log_summary.txt
        system_id = parts[1]
        benchmark = parts[2]
        scenario = parts[3]
        value = None
        with open(entry) as f:
            log = f.read().split("\n")
            for line in log:
                matches = re.match(SCENARIO_PERF_RES_RGXS[scenario], line)
                if matches is None:
                    continue
                value = float(matches.group(1))
                break
        if value is None:
            raise Exception("Could not find perf value in file: " + entry)
        results_tree.insert([system_id, benchmark, scenario], value, append=True)
    return results_tree

def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--results_dir", "-d",
        help="Specifies the directory containing the results.",
        default="results"
    )
    parser.add_argument(
        "--output_csv", "-o",
        help="Specifies the CSV to output the results in.",
        default="results_summary.csv"
    )
    parser.add_argument(
        "--metadata_file",
        help="File that stores metadata about these results",
        default="results_metadata.json"
    )
    return parser.parse_args()

def main():
    args = get_args()

    perf_vals = traverse_results(args.results_dir)
    metadata = None
    if os.path.exists(args.metadata_file):
        with open(args.metadata_file) as f:
            metadata = json.load(f)
    metadata = Tree(starting_val=metadata)

    lines = []
    for system_id in perf_vals:
        for benchmark in perf_vals[system_id]:
            for scenario in perf_vals[system_id][benchmark]:
                metric = SCENARIO_PERF_RES_RGXS[scenario].split(":")[0].strip()
                num_run = metadata.get([system_id, benchmark, scenario, "performance", "last_updated"], default=1)
                print("Using {:}/{:}/{:} num_run={:}".format(system_id, benchmark, scenario, num_run))
                num_run = int(num_run) - 1
                scores = perf_vals[system_id][benchmark][scenario]
                is_same = all([scores[i] == scores[0] for i in range(num_run)])
                if not is_same:
                    print("WARNING: perf scores are different across runs!")
                    for i in range(num_run):
                        print("    Run {:d}: {:}".format(i, scores[i]))
                lines.append(",".join([
                    system_id,
                    benchmark,
                    scenario,
                    metric,
                    str(scores[num_run])
                ]) + "\n")
    lines = sorted(lines)

    with open(args.output_csv, 'w') as f:
        f.write(",".join(["system_id", "benchmark", "scenario", "perf_metric", "perf_value"]) + "\n")
        for line in lines:
            f.write(line)

if __name__ == '__main__':
    main()
