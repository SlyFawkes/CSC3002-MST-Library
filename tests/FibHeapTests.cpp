
#include <gtest/gtest.h>
#include "../src/DataStructures/FibonacciHeap.h"

class FibonacciHeapBasicTest : public ::testing::Test {
protected:
    FibonacciHeap* fibonacciHeap{};

    void SetUp() override {
        fibonacciHeap = new FibonacciHeap();
    }
};


TEST_F(FibonacciHeapBasicTest, InsertSingleNode) {
    EXPECT_EQ(0, fibonacciHeap->nodeAmount);
    Node* node = new Node(1);
    fibonacciHeap->insert(node);
    EXPECT_EQ(1, fibonacciHeap->nodeAmount);
    EXPECT_EQ(node, fibonacciHeap->getMin());
    EXPECT_EQ(1, fibonacciHeap->getMin()->key);

}

TEST_F(FibonacciHeapBasicTest, GetMinimumSingleNode) {
    Node* node = new Node(1);
    fibonacciHeap->insert(node);
    Node* retrievednode = fibonacciHeap->getMin();
    EXPECT_EQ(node, retrievednode);
    EXPECT_EQ(1, retrievednode->key);
    EXPECT_EQ(retrievednode, fibonacciHeap->getMin());
}

TEST_F(FibonacciHeapBasicTest, InsertMultipleNodes) {
    Node* highNode = new Node(100);
    Node* lowNode = new Node(1);
    fibonacciHeap->insert(highNode);
    EXPECT_EQ(1, fibonacciHeap->nodeAmount);
    EXPECT_EQ(highNode, fibonacciHeap->getMin());

    fibonacciHeap->insert(lowNode);
    EXPECT_EQ(2, fibonacciHeap->nodeAmount);
    EXPECT_EQ(lowNode, fibonacciHeap->getMin());
}


TEST_F(FibonacciHeapBasicTest, ExtractsMinimumSingleNode) {
    Node* node = new Node(2);
    fibonacciHeap->insert(node);
    Node* extractedNode = fibonacciHeap->extractMin();
    EXPECT_EQ(node, extractedNode);
    EXPECT_EQ(2, extractedNode->key);
}

