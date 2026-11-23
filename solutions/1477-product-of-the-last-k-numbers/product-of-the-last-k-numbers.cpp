class ProductOfNumbers {
public:
    vector<int> prefix = {1};

    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= static_cast<int>(prefix.size())) {
            return 0;
        }
        return prefix.back() / prefix[prefix.size() - 1 - k];
    }
};