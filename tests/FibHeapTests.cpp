
#include <gtest/gtest.h>
#include "../src/DataStructures/FibonacciHeap.h"

class FibonacciHeapBasicTest : public ::testing::Test {
protected:
    FibonacciHeap* fibonacciHeap;
    virtual void SetUp() {
        fibonacciHeap = new FibonacciHeap();
    }
};

TEST_F(FibonacciHeapBasicTest, InsertSingleNode) {
    EXPECT_EQ(0, fibonacciHeap->nodeAmount);
    fibonacciHeap->insert(new Node(1));
    EXPECT_EQ(1, fibonacciHeap->nodeAmount);
    EXPECT_EQ(1, fibonacciHeap->getMin().key);

}


TEST_F(FibonacciHeapBasicTest, ExtractsMinimumSingleNode) {
    fibonacciHeap->insert(new Node(2));
    EXPECT_EQ(2, fibonacciHeap->extractMin()->key);
}

