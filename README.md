# obstacles-avoidance-car
an arduino obstacle avoiding car use sg90 and HC-SR04 , based on the chassis of the line_follower car.
Arduino uno 驱动的避障小车，使用sg90舵机和HC-SRO4超声波传感器

function: measure the distance  in front of the car, leftside and rightside of the car. if the distance between the car and the obstacle less than threshold , initalizing obstacle avoiding sequence , measure the leftdistance and rightdistance, choose the spin orientation.

功能：测量小车和障碍物之间的距离，如果距离小于阈值，启动避障程序。测量舵机0度和180度小车离障碍物之间的距离，根据距离选择旋转方向。
