#include "SignedKReachability.h"

void test_query_by_index(string path, double scale, string query_exp, int code) {
	string folder = query_exp + "/query_time/scale/" + to_string(static_cast<int>(scale * 100)) + "/index/";
	string online_folder = query_exp + "/query_time/scale/" + to_string(static_cast<int>(scale * 100)) + "/online/";
	clock_t ct;
	SignedKReachability r(path, scale);
	r.reorder();
	r.build_dis_label(scale, folder + "/cost.txt");

	std::ofstream index_cost(folder + "/cost.txt", std::ofstream::app);
	index_cost << "Indexing time: " << (clock()-ct)*1.0/CLOCKS_PER_SEC << "\n";
	index_cost.close();
	//string path = "/Users/lqin/Dropbox/Lu/workspace/data/sign-slashdot";
	//string path = "/Users/lqin/Dropbox/Lu/workspace/data/sign-epinions";
	// string path = "data/bitcoinalpha";
	
	// if (code & SCALE_CHECK && hop == 3) {
	for (double hop = 3; hop <= 12; hop++) {
		std::ofstream file(folder + to_string(static_cast<int>(hop)) + ".txt", std::ofstream::trunc);
		file.close();
		std::ofstream scale_file(folder + to_string(static_cast<int>(hop)) + ".txt", std::ofstream::app);

		ct = clock();
		
		// SignedKReachability r(path, scale);
		// r.reorder();
		// r.build_dis_label(scale, folder + "/cost.txt");
		
		// cout << "index construct for scale = " << scale << " finished==========================================================\n"; 
		// scale_file << "Indexing time: " << (clock()-ct)*1.0/CLOCKS_PER_SEC << "\n";
		
		int n = r.n;
		int N = 10000000;

		string line;
		std::ifstream query_file(query_exp + "/query.txt");
		int n0 = 0, n_1 = 0, n1 = 0, n_2 = 0, n2 = 0, n_3 = 0, n3 = 0;
		ct = clock();
		while (std::getline(query_file, line)) {
			// 创建字符串流用于解析每一行
			std::istringstream iss(line);

			// 定义变量来存储每行的数据
			int a, b, s ;
			iss >> a >> b >> s;
			// cout << a << " " << b << " " << s << "\n";
			int rst = r.query_reach(a,b,s,hop);
			// int rst_val = 1;
			// if (rst < 0) rst_val = 0;
			// if (r.query_brute_force(a, b,sign) != rst_val) {
			// 	cout << "rst_val = " << rst_val << ", and ================================================== error\n";
			// }
			// cout << "test " << i << " passed, res = " << rst_val << "\n";
			if(rst == -1) ++n_1;
			else if(rst == 1) ++n1;
			else if(rst == -2) ++n_2;
			else if(rst == 2) ++n2;
			else if(rst == 3) ++n3;
			else if(rst == -3) ++n_3;
			else ++n0;
		}
		cout << "query complete for hop = " << hop << "\n";

		
		

		scale_file << n_1+n_2+n_3 << " " << n1+n2+n3 << " " << n_1 << " " << n1 << " " << n_2 << " " << n2 << " " << n_3 << " " << n3 << " " << n0 << "\n";
		scale_file << (clock()-ct)*1.0/CLOCKS_PER_SEC << "\n";
		scale_file.close();


		std::ofstream online_file(online_folder + to_string(static_cast<int>(hop)) + ".txt", std::ofstream::trunc);
		online_file.close();
		std::ofstream online_scale_file(online_folder + to_string(static_cast<int>(hop)) + ".txt", std::ofstream::app);
		
		std::ifstream online_query(query_exp + "/query.txt");



		n0 = 0, n_1 = 0, n1 = 0, n_2 = 0, n2 = 0, n_3 = 0, n3 = 0;
		N = 1000;

		ct = clock();
		int count = 0;
		while (std::getline(online_query, line)) {
			if (count >= N) break;
			
			// 创建字符串流用于解析每一行
			std::istringstream iss(line);
			if ((clock()-ct)*1.0/CLOCKS_PER_SEC > 3600) break;
			// 定义变量来存储每行的数据
			int a, b, s ;
			iss >> a >> b >> s;
			// cout << a << " " << b << " " << s << "\n";
			int rst = r.query_reach_online(a,b,s,hop);
			// int rst_val = 1;
			// if (rst < 0) rst_val = 0;
			// if (r.query_brute_force(a, b,sign) != rst_val) {
			// 	cout << "rst_val = " << rst_val << ", and ================================================== error\n";
			// }
			// cout << "test " << i << " passed, res = " << rst_val << "\n";
			if(rst == -1) ++n_1;
			else if(rst == 1) ++n1;
			else if(rst == -2) ++n_2;
			else if(rst == 2) ++n2;
			else if(rst == 3) ++n3;
			else if(rst == -3) ++n_3;
			else ++n0;

			count++;
		}


		online_scale_file << n_1+n_2+n_3 << " " << n1+n2+n3 << " " << n_1 << " " << n1 << " " << n_2 << " " << n2 << " " << n_3 << " " << n3 << " " << n0 << "\n";
		online_scale_file << (clock()-ct)*1.0/CLOCKS_PER_SEC << "\n";
		online_scale_file.close();
		
	}

}

void test_query_online(string path, int hop, string query_exp, int code) {
	// clock_t ct = clock();

	// //string path = "/Users/lqin/Dropbox/Lu/workspace/data/sign-slashdot";
	// //string path = "/Users/lqin/Dropbox/Lu/workspace/data/sign-epinions";
	// // string path = "data/bitcoinalpha";


	// string folder = query_exp + "/query_time/scale/" + to_string(static_cast<int>(scale)) + "/index";

	// clock_t ct;
	// SignedKReachability r(path, scale);
	// r.reorder();
	// r.build_dis_label(scale, folder + "/cost.txt");

	// std::ofstream index_cost(folder + to_string(static_cast<int>(hop)) + ".txt", std::ofstream::app);
	// index_cost << "Indexing time: " << (clock()-ct)*1.0/CLOCKS_PER_SEC << "\n";
	// index_cost.close();
	// //string path = "/Users/lqin/Dropbox/Lu/workspace/data/sign-slashdot";
	// //string path = "/Users/lqin/Dropbox/Lu/workspace/data/sign-epinions";
	// // string path = "data/bitcoinalpha";
	// cout << "hop is " << hop << "\n";
	// // if (code & SCALE_CHECK && hop == 3) {
	// for (double hop = 3; hop <= 15; hop++) {
	// 	std::ofstream file(folder + to_string(static_cast<int>(hop)) + ".txt", std::ofstream::trunc);
	// 	file.close();
	// 	std::ofstream scale_file(folder + to_string(static_cast<int>(hop)) + ".txt", std::ofstream::app);

	// 	ct = clock();
		
	// 	SignedKReachability r(path, scale);
	// 	r.reorder();
	// 	r.build_dis_label(scale, folder + to_string(static_cast<int>(scale * 100)) + ".txt");
		
	// 	cout << "index construct for scale = " << scale << " finished==========================================================\n"; 
	// 	scale_file << "Indexing time: " << (clock()-ct)*1.0/CLOCKS_PER_SEC << "\n";
		
	// 	int n = r.n;
	// 	int N = 10000000;

	// 	string line;
	// 	std::ifstream query_file(query_exp + "/query.txt");
	// 	int n0 = 0, n_1 = 0, n1 = 0, n_2 = 0, n2 = 0, n_3 = 0, n3 = 0;
	// 	ct = clock();
	// 	while (std::getline(query_file, line)) {
	// 		// 创建字符串流用于解析每一行
	// 		std::istringstream iss(line);

	// 		// 定义变量来存储每行的数据
	// 		int a, b, s ;
	// 		iss >> a >> b >> s;
	// 		// cout << a << " " << b << " " << s << "\n";
	// 		int rst = r.query_reach(a,b,s,hop);
	// 		// int rst_val = 1;
	// 		// if (rst < 0) rst_val = 0;
	// 		// if (r.query_brute_force(a, b,sign) != rst_val) {
	// 		// 	cout << "rst_val = " << rst_val << ", and ================================================== error\n";
	// 		// }
	// 		// cout << "test " << i << " passed, res = " << rst_val << "\n";
	// 		if(rst == -1) ++n_1;
	// 		else if(rst == 1) ++n1;
	// 		else if(rst == -2) ++n_2;
	// 		else if(rst == 2) ++n2;
	// 		else if(rst == 3) ++n3;
	// 		else if(rst == -3) ++n_3;
	// 		else ++n0;
	// 	}
	// 	cout << "query complete for hop = " << h << "\n";

		
		

	// 	scale_file << n_1+n_2+n_3 << " " << n1+n2+n3 << " " << n_1 << " " << n1 << " " << n_2 << " " << n2 << " " << n_3 << " " << n3 << " " << n0 << "\n";
	// 	scale_file << (clock()-ct)*1.0/CLOCKS_PER_SEC << "\n";
	// 	scale_file.close();
	// }


	










	// string folder = query_exp + "/query_time/online/";
	// if (!std::filesystem::exists(folder)) {
	// 	try {
	// 		std::filesystem::create_directory(folder);
	// 	} catch (const std::filesystem::filesystem_error& e) {
	// 		std::cerr << "创建文件夹时出现错误: " << folder << std::endl;
	// 	}
	// }



	// string online_query_path = folder + to_string(hop) + ".txt";
	// std::ofstream file(online_query_path, std::ofstream::trunc);
	// file.close();

	// std::ofstream query_time(online_query_path, std::ofstream::app);



	// SignedKReachability r(path, 1);


	// int n = r.n, n0 = 0, n_1 = 0, n1 = 0, n_2 = 0, n2 = 0, n_3 = 0, n3 = 0;
	// int N = 10000;


	// if (code & QUERY_FROM_FILE) {
	// 	std::ifstream file(query_exp + "/query.txt");
	// 	if (!file) {
	// 		std::ofstream query_file(query_exp + "/query.txt", std::ofstream::trunc);
	// 		for (auto i = 0; i < N; ++i) {
	// 			int a = rand() % n, b = rand() % n;
	// 			bool sign = rand() % 2;
	// 			query_file << a << " " << b << " " << sign << "\n";
	// 		}
	// 		query_file.close();
	// 	}
	// 	file.close();

	// 	string line;
	// 	std::ifstream query_file(query_exp + "/query.txt");
	// 	ct = clock();
	// 	int count = 0;
	// 	while (std::getline(query_file, line)) {
	// 		// 创建字符串流用于解析每一行
	// 		if (count >= N) break;
	// 		std::istringstream iss(line);
	// 		// 定义变量来存储每行的数据
	// 		int a, b, s ;
	// 		iss >> a >> b >> s;
	// 		int rst = r.query_reach_online(a,b,s,hop);
	// 		// int rst_val = 1;
	// 		// if (rst < 0) rst_val = 0;
	// 		// if (r.query_brute_force(a, b,sign) != rst_val) {
	// 		// 	cout << "rst_val = " << rst_val << ", and ================================================== error\n";
	// 		// }
	// 		// cout << "test " << i << " passed, res = " << rst_val << "\n";
	// 		count++;
	// 		if(rst == -1) ++n_1;
	// 		else if(rst == 1) ++n1;
	// 		else if(rst == -2) ++n_2;
	// 		else if(rst == 2) ++n2;
	// 		else if(rst == 3) ++n3;
	// 		else if(rst == -3) ++n_3;
	// 		else ++n0;
	// 	}
	// } else {
	// 	ct = clock();
	// 	for(int i = 0; i < N; ++i) {
	// 		int a = rand() % n, b = rand() % n;
	// 		bool sign = rand() % 2;


	// 		int rst = r.query_reach_online(a,b,sign,hop);
	// 		// int rst_val = 1;
	// 		// if (rst < 0) rst_val = 0;
	// 		// if (r.query_brute_force(a, b,sign) != rst_val) {
	// 		// 	cout << "rst_val = " << rst_val << ", and ================================================== error\n";
	// 		// }
	// 		// cout << "test " << i << " passed, res = " << rst_val << "\n";
	// 		if(rst == -1) ++n_1;
	// 		else if(rst == 1) ++n1;
	// 		else if(rst == -2) ++n_2;
	// 		else if(rst == 2) ++n2;
	// 		else if(rst == 3) ++n3;
	// 		else if(rst == -3) ++n_3;
	// 		else ++n0;
	// 	}
	// }



	// // for(int i = 0; i < N; ++i) {
	// // 	int a = rand() % n, b = rand() % n;
	// // 	bool sign = rand() % 2;


	// // 	int rst = r.query_reach_online(a,b,sign,hop);

	// // 	if(rst == -1) ++n_1;
	// // 	else if(rst == 1) ++n1;
	// // 	else if(rst == -2) ++n_2;
	// // 	else if(rst == 2) ++n2;
	// // 	else if(rst == 3) ++n3;
	// // 	else if(rst == -3) ++n_3;
	// // 	else ++n0;
	// // }

	// // printf( "Total No=%d,Total Yes=%d,Path No=%d,Path Yes=%d,DP No=%d,DP Yes=%d,Online No=%d,Online Yes=%d,Unknown=%d\n",
	// // 		n_1+n_2+n_3, n1+n2+n3, n_1, n1, n_2, n2, n_3, n3, n0);


	// // printf( "Querying time = %0.3lf secs\n", (clock()-ct)*1.0/CLOCKS_PER_SEC);
	// cout << "query complete for hop = " << hop << "\n";

	// query_time << n_1+n_2+n_3 << " " << n1+n2+n3 << " " << n_1 << " " << n1 << " " << n_2 << " " << n2 << " " << n_3 << " " << n3 << " " << n0 << "\n";
	// query_time << (clock()-ct)*1.0/CLOCKS_PER_SEC << "\n";
}

int main(int argc, char *argv[]) {
	printf( "argc=%d\n", argc );
	for( int i = 0; i < argc; ++i )
		printf( "argv[%d]=%s\n", i, argv[i] );

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	clock_t t = clock();

	// if( argc > 1 ) {
	// }

	// if( argc <= 1) {
	int code = stoi(argv[2]);
	
	cout << "code = " << code << "\n";
	string path = argv[1];
	string dictName = path;
	dictName.erase(0, 5);
	string target_folder = "result/" + dictName;
	if (!std::filesystem::exists(target_folder)) {
		try {
			std::filesystem::create_directory(target_folder);
		} catch (const std::filesystem::filesystem_error& e) {
			std::cerr << "创建文件夹时出现错误: " << target_folder << std::endl;
		}
	}
	
	

	string query_exp = target_folder + "/query_time";
	if (!std::filesystem::exists(query_exp)) {
		try {
			std::filesystem::create_directory(query_exp);
		} catch (const std::filesystem::filesystem_error& e) {
			std::cerr << "创建文件夹时出现错误1: " << query_exp << std::endl;
		}
	}

	// if (!std::filesystem::exists(target_folder + "/scale")) {
	// 	try {
	// 		std::filesystem::create_directory(target_folder + "/scale");
	// 	} catch (const std::filesystem::filesystem_error& e) {
	// 		std::cerr << "创建文件夹时出现错误1: " << target_folder + "/scale" << std::endl;
	// 	}
	// }

	if (!std::filesystem::exists(target_folder + "/query.txt")) {
		SignedKReachability r(path, 1);
		r.reorder();
		std::ofstream query_input(target_folder + "/query.txt", std::ofstream::trunc);
		for (auto j = 0; j < 10000000; ++j) {
			int a = rand() % r.n;
			int b = rand() % r.n;
			bool sign = rand() % 2;
			query_input << a << " " << b << " " << sign << "\n";
		}
		query_input.close();

	}

	
		
	for (auto i = 0.2; i <= 1; i += 0.2) {
		if (!std::filesystem::exists(query_exp + "/scale")) {
			try {
				std::filesystem::create_directory(query_exp + "/scale");
				
			} catch (const std::filesystem::filesystem_error& e) {
				std::cerr << "创建文件夹时出现错误1: " << query_exp + "/scale" << std::endl;
			}
		}
		std::filesystem::create_directory(query_exp + "/scale/" +  to_string(static_cast<int>(i * 100)));
		std::filesystem::create_directory(query_exp + "/scale/" +  to_string(static_cast<int>(i * 100)) + "/index");
		std::filesystem::create_directory(query_exp + "/scale/" +  to_string(static_cast<int>(i * 100)) + "/online");
		std::filesystem::create_directory(query_exp + "/scale/" +  to_string(static_cast<int>(i * 100)) + "/base");
		// std::ofstream baseline(query_exp + "/scale/" +  to_string(static_cast<int>(i * 100)) + "/base", std::ofstream::trunc);
		test_query_by_index(path, i, target_folder, code);
		
		// test_query_online(path, i, target_folder, code);
		/*
		SignedKReachability r(path, i);
	
		for (auto j = 6; j <= 6; ++j) {
			std::ofstream baseline(query_exp + "/scale/" +  to_string(static_cast<int>(i * 100)) + "/base/" + to_string(j) + ".txt");
			r.reorder();
			std::ifstream query_file(target_folder + "/query.txt");
			clock_t ct = clock();
			int count = 0;
			string line;
			int total = 0;
			cout << "start calculating with hop = " << j << ", scale = " << i << "\n";
			while (std::getline(query_file, line)) {
				// 创建字符串流用于解析每一行
				if (count >= 1000 || (clock()-ct)*1.0/CLOCKS_PER_SEC > 36000) break;
				std::istringstream iss(line);
				// 定义变量来存储每行的数据
				int a, b, s ;
				iss >> a >> b >> s;
				int rst = r.query_brute_force(a,b,s, j);
				total += rst;
				// int rst_val = 1;
				// if (rst < 0) rst_val = 0;
				// if (r.query_brute_force(a, b,sign) != rst_val) {
				// 	cout << "rst_val = " << rst_val << ", and ================================================== error\n";
				// }
				// cout << "test " << i << " passed, res = " << rst_val << "\n";
				count++;
				if (count % 10 == 0) cout << "dfs complete " << count << "\n";
			}
			baseline << "complete " << count << " queries\n";
			baseline << (clock()-ct)*1.0/CLOCKS_PER_SEC << "\n";
			baseline << "true result = " << total <<  "\n";
		}
		*/
	}
	
	
	
	
		//test_query_online();
	// }
	
	t = clock() - t;
	printf( "Total time=%0.3lf seconds\n", t*1.0/CLOCKS_PER_SEC);


	



	return 0;
}
