import numpy as np
import matplotlib.pyplot as plt
import sys
import os

if os.path.isdir(sys.argv[1]):
    input_files = os.listdir(sys.argv[1])
else:
    input_files = [sys.argv[1].split('/')[-1]]

for file in input_files:
    with open('/'.join(sys.argv[1].split('/')[:-1])+'/'+file,'r') as f:
        strings = f.readlines()
    flows = {}
    for str in strings:
        if 'flow' in str:
            currentflow = str.split()[1]
            flows[currentflow] = []
        else:
            if 'Packet' not in str:
                flows[currentflow].append(list(map(int,str.split())))


    for i in flows:
        flows[i] = np.array(sorted(flows[i], key=lambda x: x[0]))
        x,y,z,a = (flows[i][:,0],flows[i][:,1],flows[i][:,2],flows[i][:,3])
        #graph
        # marker数据点样式，linewidth线宽，linestyle线型样式，color颜色
        plt.plot(x, y, marker="*", linewidth=2, linestyle="--", color="orange")
        plt.plot(x, z,  marker=".", linewidth=2)
        plt.plot(x, a,  marker=".", linewidth=2)
        plt.title("Flow "+i,fontsize=15)
        plt.xlabel("Packet Number")
        plt.ylabel("Cycle/Round")
        # 设置图例
        plt.legend(["Theoretical Departure round","Actual Departure Round","Actual Departure Cycle"], loc="upper left")
        plt.grid(True)
        # plt.show()
        plt.savefig('/'.join(sys.argv[1].split('/')[:-1])+'/'+file.split('.')[0]+'_'+i+'.png')
        plt.gcf().clear()
