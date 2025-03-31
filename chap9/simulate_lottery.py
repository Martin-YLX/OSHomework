import random
import pandas as pd

def simulate_lottery(seed, length0=100, tickets0=100, length1=100, tickets1=100):
    random.seed(seed)
    time = 0
    job0_timeleft = length0
    job1_timeleft = length1
    job0_done = None
    job1_done = None

    while job0_timeleft > 0 or job1_timeleft > 0:
        total_tickets = (tickets0 if job0_timeleft > 0 else 0) + (tickets1 if job1_timeleft > 0 else 0)
        win = random.randint(0, total_tickets - 1)
        if win < tickets0 and job0_timeleft > 0:
            job0_timeleft -= 1
            if job0_timeleft == 0:
                job0_done = time + 1
        elif job1_timeleft > 0:
            job1_timeleft -= 1
            if job1_timeleft == 0:
                job1_done = time + 1
        time += 1

    return {
        "Seed": seed,
        "Job0_Finish": job0_done,
        "Job1_Finish": job1_done,
        "Delta": abs(job0_done - job1_done)
    }

# 模拟多个种子
results = [simulate_lottery(seed) for seed in range(100)]
df = pd.DataFrame(results)

# 打印前 10 行
# print("First 10 rows:\n")
# print(df.head(10))

# 打印平均和最大 Delta
avg_delta = df["Delta"].mean()
max_delta = df["Delta"].max()
print(f"Average Delta: {avg_delta}")
print(f"Max Delta: {max_delta}")

# 打印 Delta 最大的记录
print("Records with Max Delta:")
print(df[df["Delta"] == max_delta])

