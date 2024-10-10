# qlmRos2_homework

# build
- Open: developer command prompt for vs 2022
- Go to project folder: > cd C:\Users\Asus\Documents\Git\qlmRos2_homework
- Set environment variables > call install/setup.bat
- build > colcon build

# run 
- open cmd 
- Go to project folder: > cd C:\Users\Asus\Documents\Git\qlmRos2_homework
- Set environment variables > call install/setup.bat
- run node: > ros2 run cpp_pubsub division_node

# test 
-- TEST PUBLISHER 
- open cmd 
- Go to project folder: > cd C:\Users\Asus\Documents\Git\qlmRos2_homework
- Set environment variables > call install/setup.bat
- Run test pub.: > ros2 topic pub /input_numbers std_msgs/msg/Float64MultiArray "{data: [10.0, 2.0]}"

-- TEST SUBCRIBER
- open cmd 
- Go to project folder: > cd C:\Users\Asus\Documents\Git\qlmRos2_homework
- Set environment variables > call install/setup.bat
- Run test sub.: > ros2 topic echo /division_result

# result

-- NODE 
C:\Users\Asus\Documents\Git\qlmRos2_homework>ros2 run cpp_pubsub division_node
[INFO] [1728554451.667501800] [division_node]: Init
[INFO] [1728554483.487882800] [division_node]: Msg rec.
[INFO] [1728554483.488986600] [division_node]: Divided: 10.000000 / 2.000000 = 5.000000
[INFO] [1728554484.512556400] [division_node]: Msg rec.
[INFO] [1728554484.513861100] [division_node]: Divided: 10.000000 / 2.000000 = 5.000000

-- Publisher
C:\Users\Asus\Documents\Git\qlmRos2_homework>ros2 topic pub /input_numbers std_msgs/msg/Float64MultiArray "{data: [10.0, 2.0]}"
publisher: beginning loop
publishing #1: std_msgs.msg.Float64MultiArray(layout=std_msgs.msg.MultiArrayLayout(dim=[], data_offset=0), data=[10.0, 2.0])
publishing #2: std_msgs.msg.Float64MultiArray(layout=std_msgs.msg.MultiArrayLayout(dim=[], data_offset=0), data=[10.0, 2.0])

-- Subcriber 
C:\Users\Asus\Documents\Git\qlmRos2_homework>ros2 topic echo /division_result
data: 1.0
---
data: 1.0