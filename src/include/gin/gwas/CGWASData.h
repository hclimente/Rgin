#ifndef CGWASDATA_CLASS
#define CGWASDATA_CLASS

#include "gin/globals.h"
#include "gin/utils/StringHelper.h"

#include <fstream>
#include <vector>
#include <string>
#include <map>

#include <Eigen/Dense>

/*
*CGWASData Exception Class
*/
class CGWASDataException {
	private:
		std::string __error_msg;
	public:
		CGWASDataException(std::string const& error_msg) : __error_msg(error_msg) {
			logging(GIN_ERROR, "CGWASData Exception: " + error_msg);
		}

		std::string what() {
			return __error_msg;
		}
};

/*
*Data object
*/
class GWASData {
	public:
		std::vector<std::vector<char> > raw_snps;
		std::vector<std::string> sample_ids;
		std::vector<std::string> chromosomes;
		std::vector<uint64> positions;
		std::vector<uint64> removed_snp_indices;
		std::vector<float64> snp_distance;
		std::vector<std::string> snp_identifiers;
		std::vector<std::string> phenotype_names;
		std::vector<std::string> family_ids;
		std::vector<std::string> paternal_ids;
		std::vector<std::string> maternal_ids;
		std::vector<uint> sex;
		VectorXd MAF;
		MatrixXd Y;
		VectorXd y;
		MatrixXd X;
		MatrixXd K;
		SparseMatrixXd network;
		VectorXd snp_hash;
		uint64 n_samples;
		uint64 n_snps;
		uint64 n_unique_snps;
		std::string genotype_data_type;
		std::string genotype_encoding;
};

/*
*Result data class
*/ 
class GWASResults {
	public:
        std::vector<std::string> chromosomes;
		std::vector<uint64> positions;
		VectorXd samples;
		VectorXd p_values;
		MatrixXd betas;
		MatrixXd se_betas;
		VectorXd test_statistics;
		VectorXd alternative_loglikelihoods;
		float64 null_loglikelihood;
};

class CGWASDataHelper {
	
	private:
		static VectorXd __updateMAF(MatrixXd const&);
		GWASData __data;

	public:
		static const uint additive = 0;
		static const uint recessive = 1;
		static const uint dominant = 2;
		static const uint codominant = 3;
		
		//Class methods for more flexible interactions
		void encodeHomozygousData(std::vector< std::vector<char> > const&,
					  uint64 const&, uint64 const&);
		void encodeHeterozygousData(std::vector< std::vector<char> > const&,
					  uint64 const&, uint64 const&, uint const&);

		void releaseMemory();
		MatrixXd getEncodedData();
		VectorXd getMAF();

		//static member functions for C++ only
		static void encodeHomozygousData(GWASData*);
		static void encodeHeterozygousData(GWASData*);
		static void encodeHeterozygousData(GWASData*,uint const&);
		static void filterSNPsByMAF(GWASData*,float64 const&);
		static void filterNonInformativeSNPs(GWASData*);
		//static void filterSNPsBySmallIndel(GWASData*,int const&);
		static void filterUniqueSNPs(GWASData*);
		static void createSNPHash(GWASData*);
		static GWASData removeSamples4MissingData(GWASData const&, uint const&);
		static GWASData removeSamples4MissingData(GWASData const&, uint const&, bool const);
};

#endif //CGWASDATA_CLASS
