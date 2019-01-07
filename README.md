# HierarchicalScheduling

### Input: config.txt

#### for union random trace_generator.py
#### [Flow Num] [Weight] [Flow Length] [Arrival Randomness] [Packet Size]

- Flow Num: Identify flow

- Weight: Calculate departure time              //what if (Packet Size/weight) is not integer ? 

- Flow Length: Packet number in flow

- Arrival Randomness: Calculate arrive time

- Packet Size: Packet size in flow, set to 1 now

#### for possion random trace_generator.py
#### [Flow Num] [Weight] [Flow Length] [Possion lamba] [Exp lamba] [Packet Size]

- Flow Num: Identify flow

- Weight: Calculate departure time              //what if (Packet Size/weight) is not integer ? 

- Flow Length: Packet number in flow

- Possion lamba: Calculate arrive time for first packet

- Exp lamba: Calculate arrive time: Calculate arrive time next packet

- Packet Size: Packet size in flow, set to 1 now




### Output: trace.txt
#### [Total Packet]
#### [Flow Num][Packet Num][Arrival Time][Departure time] [Packet Size]

- Total Packet: Total Num of Packets from input config

- Flow Num: Same as ‘Flow Num’ in input file

- Packet Num: Identify packet order in the same flow 

- Arrival Time: Current Packet Arrival Time = last Packet Arrival Time + Random(0, Arrival Randomness)
(first pack arrival time set to 0) 

- Departure time: 
```
Max(Current Packet Arrival Round, Last Packet Departure Round of the corresponding flow) + (1 / Weight) * Packet size  
(first pack departure time set to (1 / Weight) * Packet size)    
```

- Packet Size: Same as Input Packet Size, set to 1 now
