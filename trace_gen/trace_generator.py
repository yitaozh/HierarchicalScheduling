import sys
import random
import math
from functools import reduce

input, output = {},{}   # dictionary

Pcounter = 0
Fcounter = 0

with open(sys.argv[1], 'r') as f:
    for line in f:
        eles = line.split()
        Fcounter = Fcounter + 1
        input[eles[0]] = eles[1:]  # input: python trace_generator.py input.txt output.txt

new = []

for flow in input:
    weight = float(input[flow][0])
    new.append([flow, weight])
    flow_length, arr_rand, size = tuple(map(int,input[flow][1:]))
    Pcounter = Pcounter + int(input[flow][1])
    #dep_adder = int(math.ceil(size/weight))   # int 1/weight ?
    output[flow] = [[] for i in range(flow_length)]   # initial list
    output[flow][0] = [0, 0, size]   #  first packet is special
    for i in range(1, flow_length):
        output[flow][i].append(i)
        output[flow][i].append(output[flow][i-1][1]+random.randint(0,arr_rand))     # arrive time
        #output[flow][i].append((output[flow][i][0] \
        #                       if output[flow][i][0] > output[flow][i-1][1] \
        #                        else output[flow][i-1][1]) + dep_adder)     # departure time
        output[flow][i].append(size)  # size

output_list = sorted(sorted(reduce(lambda x,y:x+y, \
                    [[[i]+j for j in output[i]] for i in output]), \
                    key=lambda x:x[0]),key=lambda x:x[2])   # flownum first when departure time same

with open(sys.argv[2], 'w') as f:
    f.write(str(Fcounter) + '\n')
    for id in sorted(new,key=lambda x:x[0]):
        f.write(str(id[0])+' '+str(id[1])+'\n')
    f.write(str(Pcounter) + '\n')
    for out in output_list:
        f.write(' '.join(list(map(str,out)))+'\n')
