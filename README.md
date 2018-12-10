# HierarchicalScheduling

Input: config.txt
[Flow Num] [Weight] [Flow Length] [Arrival Randomness] [Packet Size]

Flow Num: Identify flow
Weight: Calculate departure time              ///what if (Packet Size/weight) is not integer ? 
Flow Length: Packet number in flow
Arrival Randomness: Calculate arrive time
Packet Size: Packet size in flow, set to 1 now



Output: trace.txt
[Flow Num][Packet Num][Arrival Time][Departure time] [Packet Size]

Flow Num: Same as ‘Flow Num’ in input file
Packet Num: Identify packet order in the same flow 
Arrival Time: Current Packet Arrival Time = last Packet Arrival Time + Random(0, Arrival Randomness)
(first pack arrival time set to 0) 
Departure time: Max(Current Packet Arrival Time, Last Packet Departure time) + (1/Weight) * Packet size  
(first pack departure time set to (1/Weight) * Packet size)    
Packet Size: Same as Input Packet Size, set to 1 now
