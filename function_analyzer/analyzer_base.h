//
// Created by studio25 on 02.10.2021.
//

#ifndef TIDSMATARE_FUNCTION_ANALYZER_ANALYZER_BASE_H_
#define TIDSMATARE_FUNCTION_ANALYZER_ANALYZER_BASE_H_

class AnalyzerBase {
private:
  ///
  virtual void InputData() = 0;
  virtual void DeleteOutliers(const double& percentage) = 0;
  virtual void OutputData() = 0;
};


#endif // TIDSMATARE_FUNCTION_ANALYZER_ANALYZER_BASE_H_
