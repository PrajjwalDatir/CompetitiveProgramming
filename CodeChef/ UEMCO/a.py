a = [[3, 5], [5, 7], [11, 13], [17, 19], [29, 31], [41, 43], [59, 61], [71, 73], [101, 103], [107, 109], [137, 139], [149, 151], [179, 181], [191, 193], [197, 199], [227, 229], [239, 241], [269, 271], [281, 283], [311, 313], [347, 349], [419, 421], [431, 433], [461, 463], [521, 523], [569, 571], [599, 601], [617, 619], [641, 643], [659, 661], [809, 811], [821, 823], [827, 829], [857, 859], [881, 883], [1019, 1021], [1031, 1033], [1049, 1051], [1061, 1063], [1091, 1093], [1151, 1153], [1229, 1231], [1277, 1279], [1289, 1291], [1301, 1303], [1319, 1321], [1427, 1429], [1451, 1453], [1481, 1483], [1487, 1489], [1607, 1609], [1619, 1621], [1667, 1669], [1697, 1699], [1721, 1723], [1787, 1789], [1871, 1873], [1877, 1879], [1931, 1933], [1949, 1951], [1997, 1999], [2027, 2029], [2081, 2083], [2087, 2089], [2111, 2113], [2129, 2131], [2141, 2143], [2237, 2239], [2267, 2269], [2309, 2311], [2339, 2341], [2381, 2383], [2549, 2551], [2591, 2593], [2657, 2659], [2687, 2689], [2711, 2713], [2729, 2731], [2789, 2791], [2801, 2803], [2969, 2971], [2999, 3001], [3119, 3121], [3167, 3169], [3251, 3253], [3257, 3259], [3299, 3301], [3329, 3331], [3359, 3361], [3371, 3373], [3389, 3391], [3461, 3463], [3467, 3469], [3527, 3529], [3539, 3541], [3557, 3559], [3581, 3583], [3671, 3673], [3767, 3769], [3821, 3823], [3851, 3853], [3917, 3919], [3929, 3931], [4001, 4003], [4019, 4021], [4049, 4051], [4091, 4093], [4127, 4129], [4157, 4159], [4217, 4219], [4229, 4231]]
q=int(raw_input())
while q:
	q-=1
	raw_input()
	n = int(raw_input())
	numb = []
	# for i in range(n):
		# numb.append(int(raw_input()))
	raw_input()
	numb = map(int, raw_input().split())
	raw_input()
	sub = raw_input()
	raw_input()
	k = int(raw_input())
	real = ''
	for i in sub:
		val = int(i)+k
		val = a[val-1][1]
		real+=str(val)[0]
	count = 0
	for i in numb:
		if(real in str(i)):
			print i
			count+=1
	if(count==0):
		print "No Numbers Match"