
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
    Node* retrievedNode = fibonacciHeap->getMin();
    EXPECT_EQ(node, retrievedNode);
    EXPECT_EQ(1, retrievedNode->key);
    EXPECT_EQ(retrievedNode, fibonacciHeap->getMin());
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

TEST_F(FibonacciHeapBasicTest, DecreaseKeySingleNode) {
    Node* node = new Node(2);
    fibonacciHeap->insert(node);
    fibonacciHeap->decreaseKey(node, 1);
    EXPECT_EQ(1, fibonacciHeap->getMin()->key);
}

TEST_F(FibonacciHeapBasicTest, DecreaseKeyLargerValueNode) {
    Node* node = new Node(2);
    fibonacciHeap->insert(node);
    fibonacciHeap->decreaseKey(node, 3);
    EXPECT_EQ(2, fibonacciHeap->getMin()->key);
}

TEST_F(FibonacciHeapBasicTest, DecreseKeyNonMinimumNode) {
    Node* lowerNode = new Node(5);
    Node* higherNode = new Node(10);
    fibonacciHeap->insert(lowerNode);
    fibonacciHeap->insert(higherNode);
    EXPECT_EQ(lowerNode, fibonacciHeap->getMin());
    fibonacciHeap->decreaseKey(higherNode, 1);
    EXPECT_EQ(higherNode, fibonacciHeap->getMin());
}

TEST_F(FibonacciHeapBasicTest, FibHeapUnion) {
    FibonacciHeap* fibonacciHeap2 = new FibonacciHeap();
    Node* lowerNode1 = new Node(5);
    Node* higherNode1 = new Node(15);
    Node* lowerNode2 = new Node(10);
    Node* higherNode2 = new Node(20);

    fibonacciHeap->insert(lowerNode1);
    fibonacciHeap->insert(higherNode1);

    fibonacciHeap2->insert(lowerNode2);
    fibonacciHeap2->insert(higherNode2);

    fibonacciHeap->fibHeapUnion(*fibonacciHeap2);

    EXPECT_EQ(4, fibonacciHeap->nodeAmount);
    EXPECT_EQ(lowerNode1, fibonacciHeap->extractMin());
    EXPECT_EQ(lowerNode2, fibonacciHeap->extractMin());
}

TEST_F(FibonacciHeapBasicTest, MultiExtract) {
    Node* lowerNode1 = new Node(5);
    Node* higherNode1 = new Node(15);
    Node* lowerNode2 = new Node(10);
    Node* higherNode2 = new Node(20);

    fibonacciHeap->insert(lowerNode1);
    fibonacciHeap->insert(higherNode1);
    fibonacciHeap->insert(lowerNode2);
    fibonacciHeap->insert(higherNode2);


    EXPECT_EQ(lowerNode1, fibonacciHeap->extractMin());
    EXPECT_EQ(lowerNode2, fibonacciHeap->extractMin());
    EXPECT_EQ(higherNode1, fibonacciHeap->extractMin());
    EXPECT_EQ(higherNode2, fibonacciHeap->extractMin());
}

TEST_F(FibonacciHeapBasicTest, InsertExtractInsert) {
    Node* lowerNode1 = new Node(5);
    Node* higherNode1 = new Node(15);
    Node* lowerNode2 = new Node(10);
    Node* higherNode2 = new Node(20);

    fibonacciHeap->insert(lowerNode1);
    fibonacciHeap->insert(higherNode1);
    fibonacciHeap->insert(lowerNode2);
    fibonacciHeap->insert(higherNode2);


    EXPECT_EQ(lowerNode1, fibonacciHeap->extractMin());
    EXPECT_EQ(lowerNode2, fibonacciHeap->extractMin());

    Node* lowerNode3 = new Node(1);
    Node* higherNode3 = new Node(25);
    fibonacciHeap->insert(lowerNode3);
    fibonacciHeap->insert(higherNode3);

    EXPECT_EQ(lowerNode3, fibonacciHeap->extractMin());
    EXPECT_EQ(higherNode1, fibonacciHeap->extractMin());
    EXPECT_EQ(higherNode2, fibonacciHeap->extractMin());
    EXPECT_EQ(higherNode3, fibonacciHeap->extractMin());
}