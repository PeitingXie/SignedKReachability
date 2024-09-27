#include "SignedReachability.h"

void test_query_by_index() {
	clock_t ct = clock();

	//string path = "/Users/lqin/Dropbox/Lu/workspace/data/sign-slashdot";
	//string path = "/Users/lqin/Dropbox/Lu/workspace/data/sign-epinions";
	string path = "data/bitcoinalpha";
	SignedReachability r(path);
	r.reorder();
	r.build_reach_label(1);

	printf( "Indexing time = %0.3lf secs\n", (clock()-ct)*1.0/CLOCKS_PER_SEC);

	ct = clock();

	int n = r.n, n0 = 0, n_1 = 0, n1 = 0, n_2 = 0, n2 = 0, n_3 = 0, n3 = 0;
	int N = 1000000;


	for(int i = 0; i < N; ++i) {
		int a = rand() % n, b = rand() % n;
		bool sign = rand() % 2;


		int rst = r.query_reach(a,b,sign);
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

	printf( "Total No=%d,Total Yes=%d,Path No=%d,Path Yes=%d,DP No=%d,DP Yes=%d,Online No=%d,Online Yes=%d,Unknown=%d\n",
			n_1+n_2+n_3, n1+n2+n3, n_1, n1, n_2, n2, n_3, n3, n0);

	printf( "Querying time = %0.3lf secs\n", (clock()-ct)*1.0/CLOCKS_PER_SEC);
}

void test_query_online() {
	clock_t ct = clock();

	//string path = "/Users/lqin/Dropbox/Lu/workspace/data/sign-slashdot";
	//string path = "/Users/lqin/Dropbox/Lu/workspace/data/sign-epinions";
	string path = "data/bitcoinalpha";
	SignedReachability r(path);

	ct = clock();

	int n = r.n, n0 = 0, n_1 = 0, n1 = 0, n_2 = 0, n2 = 0, n_3 = 0, n3 = 0;
	int N = 10000;


	for(int i = 0; i < N; ++i) {
		int a = rand() % n, b = rand() % n;
		bool sign = rand() % 2;


		int rst = r.query_reach_online(a,b,sign);
		

		if(rst == -1) ++n_1;
		else if(rst == 1) ++n1;
		else if(rst == -2) ++n_2;
		else if(rst == 2) ++n2;
		else if(rst == 3) ++n3;
		else if(rst == -3) ++n_3;
		else ++n0;
	}

	printf( "Total No=%d,Total Yes=%d,Path No=%d,Path Yes=%d,DP No=%d,DP Yes=%d,Online No=%d,Online Yes=%d,Unknown=%d\n",
			n_1+n_2+n_3, n1+n2+n3, n_1, n1, n_2, n2, n_3, n3, n0);


	printf( "Querying time = %0.3lf secs\n", (clock()-ct)*1.0/CLOCKS_PER_SEC);
}

int main(int argc, char *argv[]) {
	printf( "argc=%d\n", argc );
	for( int i = 0; i < argc; ++i )
		printf( "argv[%d]=%s\n", i, argv[i] );

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	clock_t t = clock();

	if( argc > 1 ) {
	}

	if( argc <= 1) {
		test_query_by_index();
		// test_query_online();
	}

	t = clock() - t;
	printf( "Total time=%0.3lf seconds\n", t*1.0/CLOCKS_PER_SEC);

	return 0;
}
