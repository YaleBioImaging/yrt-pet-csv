#pragma once

#include "yrt-pet/datastruct/PluginFramework.hpp"
#include "yrt-pet/datastruct/projection/ListMode.hpp"
#include "yrt-pet/datastruct/scanner/Scanner.hpp"

#include <memory>

namespace yrt::csv
{
	class CSVListMode : public ListMode
	{
	public:
		CSVListMode(const Scanner& pr_scanner, const std::string& filename);

		size_t count() const override;
		float getProjectionValue(bin_t id) const override;
		void setProjectionValue(bin_t id, float val) override;
		timestamp_t getTimestamp(bin_t id) const override;
		det_id_t getDetector1(bin_t id) const override;
		det_id_t getDetector2(bin_t id) const override;

		// For registering the plugin
		static std::unique_ptr<ProjectionData>
		    create(const Scanner& scanner, const std::string& filename,
		           const io::OptionsResult& pluginOptions);
		static plugin::OptionsListPerPlugin getOptions();

	private:
		std::vector<timestamp_t> timestamp_vec;
		std::vector<det_id_t> d1_vec;
		std::vector<det_id_t> d2_vec;
		std::vector<float> projValue_vec;
	};
}  // namespace yrt::csv
