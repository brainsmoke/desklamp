
#
# repeated interrupt approximator using leap ticks
#

old_freq, new_freq = 60, 2**15

r=new_freq/old_freq
#r=new_freq/1000
best, best_e, best_t = -1, 1, -1

for i in range(1,101):
    m = r*i
    m_round = round(m)
    d = m - m_round
    e = abs(d)/m_round
    if e < best_e:
        print(i, e)
        best_e = e
        best = i
        best_t = m_round

intervals = []
for i in range(best):
	intervals.append(int((i+1)*best_t/best) - int(i*best_t/best))

count = { k:0 for k in set(intervals) }
for v in intervals:
	count[v] += 1

count = list(count.items())
print(count)

leap_val, normal_val = count[0][0], count[1][0]
if count[0][1] > count[1][1]:
	leap_val, normal_val = normal_val, leap_val

leaps = [ i for i, v in enumerate(intervals) if v == leap_val ]

print("""

#define LEAP_VAL   ({}-1)
#define NORMAL_VAL ({}-1)
#define PERIOD     ({})

const uint8_t leap_tick[] =
{{
    {},

    LEAP_END
}};
""".format(leap_val, normal_val, best, ', '.join(str(i) for i in leaps)))


print (best, best_t, best_t/best)

