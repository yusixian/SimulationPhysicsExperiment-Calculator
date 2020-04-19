from math import *
print("元电荷标准值采用1.602e-19")
e_std = 1.602
print("计算结果均保留4位有效数字\n")
t = []
U = []
for i in range(8):
    U.append(eval(input("请输入第{}次测得平衡电压(V)\n".format(i+1))))
    t.append(eval(input("请输入第{}次测得油滴下降2mm所用时间(s)\n".format(i+1))))
U = sum(U)/len(U)
t = sum(t)/len(t)
print("平均平衡电压为{:.2f}V".format(U))
print("油滴下降2mm平均时间为{:.2f}s".format(t))

q = 1.43 / ((t*(1+0.02*t**0.5))**1.5 * U) * 1e5
e_computed = q / round(q/e_std)
RE = abs(e_computed-e_std)/e_std
print("测得油滴的带电量 q = {:.4f}".format(q))
print("测得基本电荷的带电量 e = {:.4f}".format(e_computed))
print("测量值与已知值的误差 RE(%) = {:.4%}".format(RE))
input()