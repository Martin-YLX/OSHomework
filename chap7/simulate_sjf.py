import matplotlib.pyplot as plt

def sjf(jobs):
    jobs = sorted(jobs, key=lambda x: x['burst_time'])
    current_time = 0
    response_times = []
    for job in jobs:
        response_time = current_time - job['arrival_time']
        response_times.append(response_time)
        current_time += job['burst_time']
    return response_times

def simulate_sjf_avg_response(job_length):
    jobs = [{'arrival_time': 0, 'burst_time': job_length + i * 100, 'id': i} for i in range(3)]
    response_times = sjf(jobs)
    return sum(response_times) / len(response_times)

lengths = [100, 200, 300, 400, 500]
avg_responses = [simulate_sjf_avg_response(l) for l in lengths]

plt.plot(lengths, avg_responses, marker='o')
plt.xlabel("Base Job Length")
plt.ylabel("Average Response Time (SJF)")
plt.title("SJF Response Time Trend with Increasing Job Length")
plt.grid(True)
plt.show()
