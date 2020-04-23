data = input("请按顺序(升序/降序均可)在一行里输入16个测量的数值(mm)：\n")
mm = data.split()
for i in range(16):
	mm[i] = float(mm[i]) * 1e-3

D = []
for i in range(8):
	D.append(abs(mm[i]-mm[-i-1]))
	print("直径D[{}] = {:.3f}mm".format(i+1, D[i]*1e3))

squareDiffAvg = 0
for i in range(4):
	squareDiffAvg += D[i] ** 2 - D[i+4] ** 2
squareDiffAvg /= 4
R = squareDiffAvg / (80 * 589 * 1e-9 )
print("最终求得R = {:.3f}m".format(R))
input()