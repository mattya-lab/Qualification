#include<stdio.h>

typedef struct {
	char pr_code[8 + 1] = {};
	int job_term;
	int target_term;
}JOB;

void job_scheduling(int num_s, JOB job[], int job_sch[]);
void print_schedule(int num_s, JOB job[], int job_sch[]);

int main() {
	int num_s = 5;

	JOB job[5] = {
		{ "APL12339", 25, 27 },
		{ "GGL08001", 27, 29 },
		{ "MS016101", 21, 30 },
		{ "CAN03022", 28, 77 },
		{ "ORA14031", 12, 93 },
	};
	//int job_sch[5] = {};
	int job_sch[5] = { 0, 2, 1, 4, 3 };

	//job_scheduling(num_s, job, job_sch);
	print_schedule(num_s, job, job_sch);
}

void print_schedule(int num_s, JOB job[], int job_sch[]) {
	int wt = 0;
	int ft = 0;
	int wt_sum = 0;
	for (int i = 0; i < num_s; i++) {
		ft += job[job_sch[i]].job_term;
		if (ft > job[job_sch[i]].target_term) {
			wt = ft - job[job_sch[i]].target_term;
			wt_sum += wt;
		}
		else {
			wt = 0;
		}
		printf("%3d %10s, %10d, %10d\n", i + 1, job[job_sch[i]].pr_code, wt, wt_sum);
	}
}

void job_scheduling(int num_s, JOB job[], int job_sch[])
{
	for (int i = 0; i < num_s; i++) { job_sch[i] = i; }
	int ft = 0;
	int i = 0;
	while (i < num_s - 1) {
		int ft_a = ft;
		int ft_b = ft;
		int wt_a = 0;
		int wt_b = 0;
		for (int j = 0; j < 2; j++) {
			ft_a += job[job_sch[i + j]].job_term;
			if (ft_a > job[job_sch[i + j]].target_term) {
				wt_a += ft_a - job[job_sch[i + j]].target_term;
			}
			ft_b += job[job_sch[i - j + 1]].job_term;
			if (ft_b > job[job_sch[i - j + 1]].target_term) {
				wt_b += ft_b - job[job_sch[i - j + 1]].target_term;
			}
		}

		if (wt_a > wt_b) {
			int job_no = job_sch[i];
			job_sch[i] = job_sch[i + 1];
			job_sch[i + 1] = job_no;
			if (i > 0) {
				ft -= job[job_sch[--i]].job_term;
			}
			else {
				printf("debug\n");
				ft += job[job_sch[i++]].job_term;
			}
		}
	}
}