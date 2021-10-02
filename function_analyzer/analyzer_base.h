//
// Created by studio25 on 02.10.2021.
//

#ifndef TIDSMATARE_FUNCTION_ANALYZER_ANALYZER_BASE_H_
#define TIDSMATARE_FUNCTION_ANALYZER_ANALYZER_BASE_H_
namespace function_analyzer {
enum class ClockResolution { SECONDS, MILLISECONDS, MICROSECONDS, NANOSECONDS };

class AnalyzerBase {
private:
  /// handles incoming data, checks if there's any and copies it to intern
  /// memory
  virtual void InputData() = 0;
  /// display collected data
  virtual void OutputData() = 0;

  /// first of many functions handling stored data,
  /// by default every Analyzer Class is able to distinguish outliers from the
  /// data group
  /// \param percentage deviation from average value, if the measurement is to
  /// radical and doesn't fit in the
  virtual void DeleteOutliers(const double &percentage) = 0;

  /// calculates biggest clock resolution
  void CalculateTimeResolution();


  ClockResolution time_resolution_ = ClockResolution::SECONDS;

};
} // namespace function_analyzer

#endif // TIDSMATARE_FUNCTION_ANALYZER_ANALYZER_BASE_H_
