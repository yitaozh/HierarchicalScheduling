# HierarchicalScheduling

### Input: config.txt



#### for union random trace_generator.py
#### [Flow Id] [Flow Weight] [Flow Length] [Arrival Randomness] [Packet Size]

- Flow Id: Identify flow order from input config

- Flow Weight: Calculate departure time              //what if (Packet Size/weight) is not integer ? 

- Flow Length: Packet number in flow

- Arrival Randomness: Calculate arrive time

- Packet Size: Packet size in flow, set to 1 now



#### for possion random trace_generator.py
#### [Flow Id] [Flow Weight] [Flow Length] [Possion lamba] [Exp lamba] [Packet Size]

- Flow Id: Identify flow order from input config

- Flow Weight: Calculate departure time              //what if (Packet Size/weight) is not integer ? 

- Flow Length: Packet number in flow

- Possion lamba: Calculate arrive time for first packet

- Exp lamba: Calculate arrive time: Calculate arrive time next packet

- Packet Size: Packet size in flow, set to 1 now



### Output: trace.txt

#### [Total Flow]
#### [Flow Id] [Flow Weight]
#### [Total Packet]
#### [flow Id] [Packet Order] [Arrive Cycle] [Packet Size]

- Total Flow : Total Num of Flows from input config

- Flow Id: Identify flow order from input config 

- Flow Weight: Calculate departure time 

- Total Packet: Total Num of Packets from input config

- Packet Order: Identify packet order in the same flow 

- Arrive Cycle: Current Packet Arrival Time = last Packet Arrival Time + Random.union/exp
(first pack arrival time set to 0 or possion) 

- Packet Size: Packet size in flow, set to 1 now




For calculate departure time:
```
Max(Current Packet Arrival Round, Last Packet Departure Round of the corresponding flow) + (1 / Weight) * Packet size  
(first pack departure time set to (1 / Weight) * Packet size)    
```
