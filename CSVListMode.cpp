#include "CSVListMode.hpp"

#include "csv.hpp"

CSVListMode::CSVListMode(const Scanner& p_scanner,
                         const std::string& filename)
    : scanner(p_scanner)
{
	// READ YOUR FILE FORMAT HOWEVER YOU'D LIKE HERE
	csv::CSVFormat format;
	format.no_header();
	csv::CSVReader reader(filename, format);
	for (csv::CSVRow& row : reader)
	{
		timestamp_vec.push_back(row[0].get<timestamp_t>());
		d1_vec.push_back(row[1].get<det_id_t>());
		d2_vec.push_back(row[2].get<det_id_t>());
		projValue_vec.push_back(row[3].get<float>());
	}
}

size_t CSVListMode::count() const
{
	// RETURN THE NUMBER OF EVENTS HERE
	return timestamp_vec.size();
}

float CSVListMode::getProjectionValue(bin_t id) const
{
	// RETURN THE PROJECTION VALUE HERE
	return projValue_vec[id];
}

void CSVListMode::setProjectionValue(bin_t id, float val)
{
	// SET PROJECTION VALUE HERE. IF NOT POSSIBLE, THROW RUNTIME ERROR
	projValue_vec[id] = val;
}

timestamp_t CSVListMode::getTimestamp(bin_t id) const
{
	// RETURN TIMESTAMP OF THE EVENT HERE
	return timestamp_vec[id];
}

det_id_t CSVListMode::getDetector1(bin_t id) const
{
	// RETURN DETECTOR 1 OF THE EVENT HERE
	return d1_vec[id];
}

det_id_t CSVListMode::getDetector2(bin_t id) const
{
	// RETURN DETECTOR 2 OF THE EVENT HERE
	return d2_vec[id];
}

std::unique_ptr<ProjectionData>
    CSVListMode::create(const Scanner& scanner, const std::string& filename,
                        const Plugin::OptionsResult& pluginOptions)
{
	(void)pluginOptions;  // No extra options
	return std::make_unique<CSVListMode>(scanner, filename);
}

Plugin::OptionsListPerPlugin CSVListMode::getOptions()
{
	// No extra options
	return {};
}

REGISTER_PROJDATA_PLUGIN("CSV", CSVListMode, CSVListMode::create,
                         CSVListMode::getOptions)
