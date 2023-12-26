#pragma once
#include<iostream>
#include <random>
#include <fstream>


namespace sorts {
	struct stats {
		size_t comparison_count = 0;
		size_t copy_count = 0;
	};


	stats sort_choice(std::vector<int>& data) {
		stats stat;
		size_t size = data.size();
		for (size_t i = 0; i < size - 1; i++) {
			size_t min_index = i;
			for (size_t j = i + 1; j < size; j++) {
				stat.comparison_count++;
				if (data[j] < data[min_index]) {
					min_index = j;
				}
			}
			if (min_index != i) {
				stat.copy_count++;
				int temp = data[min_index];
				data[min_index] = data[i];
				data[i] = temp;
			}
		}
		return stat;
	}

	stats shaker_sort(std::vector<int>& data) {
		stats stat;
		int control = data.size() - 1;
		int left = 0, right = control;
		do {
			for (int i = left; i < right; i++) {
				stat.comparison_count++;
				if (data[i] > data[i + 1]) {
					std::swap(data[i], data[i + 1]);
					stat.copy_count++;
					control = i;
				}
			}
			right = control;
			for (int i = right; i > left; i--) {
				stat.comparison_count++;
				if (data[i] < data[i - 1]) {
					std::swap(data[i], data[i - 1]);
					stat.copy_count++;
					control = i;
				}
			}
			left = control;
		} while (left < right);
		return stat;
	}

	stats comb_sort(std::vector<int>& data) {
		stats cur_stat;
		double factor = 1.2473309;
		int step = data.size() - 1;
		while (step >= 1)
		{
			for (int i = 0; i + step < data.size(); i++)
			{
				cur_stat.comparison_count++;
				if (data[i] > data[i + step])
				{
					cur_stat.copy_count++;
					std::swap(data[i], data[i + step]);
				}
			}
			step /= factor;
		}
		return cur_stat;
	}






	stats one_random_comb(int size, int seed) {
		std::vector<int> temp;
		std::mt19937 generator(seed);
		std::uniform_int_distribution<> distribution(0, 10000);
		for (int i = 0; i < size; i++) { 
			temp.push_back(distribution(generator)); 
		}
		return comb_sort(temp);
	}
	
	void stat_random_comb() {
		int mas[] = { 1000,3000,5000,10000,25000,50000,100000 };
		std::ofstream file;
		file.open("D:\\AISD_Laba_3\\file\\random_choise.txt");
		for (int i = 0;i < 7;i++) {
			stats mid;
			for (int j = 0;j < 100;j++) {
				stats vr = one_random_comb(mas[i], j);
				mid.comparison_count += vr.comparison_count;
				mid.copy_count += vr.copy_count;
			}
			mid.comparison_count /= 100;
			mid.copy_count /= 100;
			std::cout<< mas[i] << " " << mid.comparison_count << " " << mid.copy_count << std::endl;
			if (file.is_open()) { file << mas[i] << " " << mid.comparison_count << " " << mid.copy_count << std::endl; }
		}
		file.close();
	}


	stats one_order_comb(int size, int seed) {
		std::vector<int> temp;
		for (int i = 0; i < size; i++) { 
			temp.push_back(i);
		}
		return comb_sort(temp);
	}

	void stat_order_comb() {
		int mas[] = { 1000,3000,5000,10000,25000,50000,100000 };
		std::ofstream file;
		file.open("D:\\AISD_Laba_3\\file\\order_comb.txt");
		for (int i = 0;i < 7;i++) {
			stats mid;
			for (int j = 0;j < 100;j++) {
				stats vr = one_order_comb(mas[i], j);
				mid.comparison_count += vr.comparison_count;
				mid.copy_count += vr.copy_count;
			}
			mid.comparison_count /= 100;
			mid.copy_count /= 100;
			std::cout << mas[i] << " " << mid.comparison_count << " " << mid.copy_count << std::endl;
			if (file.is_open()) { file << mas[i] << " " << mid.comparison_count << " " << mid.copy_count << std::endl; }
		}
		file.close();
	}


	stats one_revers_comb(int size, int seed) {
		std::vector<int> temp;
		for (int i =size; i >0; i--) {
			temp.push_back(i);
		}
		return comb_sort(temp);
	}

	void stat_revers_comb() {
		int mas[] = { 1000,3000,5000,10000,25000,50000,100000 };
		std::ofstream file;
		file.open("D:\\AISD_Laba_3\\file\\revers_comb.txt");
		for (int i = 0;i < 7;i++) {
			stats mid;
			for (int j = 0;j < 100;j++) {
				stats vr = one_revers_comb(mas[i], j);
				mid.comparison_count += vr.comparison_count;
				mid.copy_count += vr.copy_count;
			}
			mid.comparison_count /= 100;
			mid.copy_count /= 100;
			std::cout << mas[i] << " " << mid.comparison_count << " " << mid.copy_count << std::endl;
			if (file.is_open()) { file << mas[i] << " " << mid.comparison_count << " " << mid.copy_count << std::endl; }
		}
		file.close();
	}







	