#include <iostream>
#include <vector>
#include <cmath>

// recursive implementation of binary search
bool r_binarySearch(std::vector<int> keys, int searchedKey) {
    int sizeOfKeysVector = std::floor(keys.size());
    // if the size of the vector is odd, then we subtract one from the 'floored value'; else, we only 'floor the value'
    int middle = (sizeOfKeysVector % 2 == 0) ? std::floor(sizeOfKeysVector / 2) - 1 : std::floor(sizeOfKeysVector / 2);
    int keyInTheMiddle = keys.at(middle);

    // base case: if found at the middle, return the position
    if (keyInTheMiddle == searchedKey)
        return true;
        // the recursion step (we well not allow to recurse if the size of the vector is 1)
    else if (searchedKey < keys.at(middle) && sizeOfKeysVector > 1)
        // the new vector is from the beginning of the current-recursion-step's one and the middle - 1
        // note that here one position has been already subtracted from the 'real middle'
        return r_binarySearch(std::vector<int>(keys.begin(), keys.begin() + middle), searchedKey);
    else if (searchedKey > keys.at(middle) && sizeOfKeysVector > 1)
        // the new vector is from the middle + 1 and the end from the current-recursion-step's vector
        return r_binarySearch(std::vector<int>(keys.begin() + middle + 1, keys.end()), searchedKey);
}

int main() {
    // test vector
    std::vector<int> keys = {1, 3, 4, 5, 6, 8};

    // test searches
    for (int testValueCounter = 1; testValueCounter <= 10; testValueCounter++) {
        if (r_binarySearch(keys, testValueCounter))
            std::cout << "Binary search (rec): " << testValueCounter << " was found!" << std::endl;
        else
            std::cout << "Binary search (rec): " << testValueCounter << " was not found!" << std::endl;
    }

    return 0;
}