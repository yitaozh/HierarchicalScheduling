import sys
import random
import math
from functools import reduce

input, output = {}, {}   # dictionary

with open(sys.argv[1], 'r') as f:
    for line in f:
        eles = line.split()
        input[eles[0]] = eles[1:]      # input: python trace_generator.py input.txt output.txt

for flow in input:
    weight = float(input[flow][0])
    flow_length, arr_rand, size = tuple(map(int,input[flow][1:]))
    dep_adder = math.ceil(size/weight)   # int 1/weight ?
    output[flow] = [[] for i in range(flow_length)]   # initial list
    output[flow][0] = [0, dep_adder, size]   #  first packet is special
    for i in range(1, flow_length):
        output[flow][i].append(output[flow][i-1][0]+random.randint(0,arr_rand))     # arrive time
        output[flow][i].append((output[flow][i][0] \
                                if output[flow][i][0] > output[flow][i-1][1] \
                                else output[flow][i-1][1]) + dep_adder)     # departure time
        output[flow][i].append(size)  # size

output_list = sorted(sorted(reduce(lambda x,y:x+y, \
                    [[[i]+j for j in output[i]] for i in output]), \
                    key=lambda x:x[0]),key=lambda x:x[2])   # flownum first when departure time same

with open(sys.argv[2], 'w') as f:
    for out in output_list:
        f.write(' '.join(list(map(str,out)))+'\n')
