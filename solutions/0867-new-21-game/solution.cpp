
template <typename T>
class CircularBuffer {
 public:
  explicit CircularBuffer(int min_size) : data_(1 << BitLen(min_size)), mask_(data_.size() - 1) {}

  static constexpr int BitLen(int min_size) {
    return 32 - __builtin_clz(min_size);
  }

  T& operator[](int index) {
    return data_[index & mask_];
  }

  const T& operator[](int index) const {
    return data_[index & mask_];
  }

  int Capacity() const {
    return data_.size();
  }

  int mask() const { return mask_; }

 private:
  std::vector<T> data_;
  const uint mask_;
};

class Solution {
 public:
  double new21Game(int n, int k, int maxPts) {
    if (k == 0 || n - k + 1 >= maxPts) {
      return 1;
    }
    const double kFactor = 1.0 / maxPts;
    if (maxPts + 1 >= n) {
      return std::pow(1 + kFactor, k - 1) / maxPts * (n - k + 1);
    }

    CircularBuffer<double> dp(maxPts + 1);
    dp[0] = 1;
    double sum = 1;
    for (int i = 1; i < k; ++i) {
      dp[i] = sum * kFactor;
      sum += dp[i] - dp[i - maxPts];
    }
    double answer = 0;
    for (int i = k; i <= n; ++i) {
      answer += sum * kFactor;
      sum -= dp[i - maxPts];
    }
    return answer;
  }
};
