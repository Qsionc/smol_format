/**
 *  @author:    Qsionc
 *  @date:      30/07/2021
 *  @file:      main-test.cpp
 *  @brief:     Testing suite for smol::format and additional classes
 *  @Copyright: This software is free to use and distribute free of charge.
 */

#include <gtest/gtest.h>
#include <format.h>

class TestSmolFormatFixture : public ::testing::Test {
public:
    ~TestSmolFormatFixture() override = default;

protected:
    ulong it{0}, count{0};
    std::string formatted;
    std::stringstream ss;

    void SetUp() override {
        it = 0;
        count = 0;
        ss.str("");
    }
};

TEST_F(TestSmolFormatFixture, test_smol_detail_to_string) {
    ASSERT_EQ("42", smol::detail::to_string(42));
    ASSERT_EQ("Test Const Char*", smol::detail::to_string("Test Const Char*"));
    char test[] = "Test Char (&)[]";
    ASSERT_EQ(test, smol::detail::to_string(test));
    std::string test_string("Test String");
    ASSERT_EQ(test_string, smol::detail::to_string(test_string));
    ASSERT_EQ("Test RValue String", smol::detail::to_string(std::string("Test RValue String")));
}

TEST_F(TestSmolFormatFixture, test_smol_detail_find_index_good) {
    ASSERT_EQ(4, smol::detail::find_index("{4}", it, count));
    ASSERT_EQ(3, count);
    ASSERT_EQ(0, it);
}

TEST_F(TestSmolFormatFixture, test_smol_detail_find_index_not_parenthesis) {
    ASSERT_EQ(-2, smol::detail::find_index("4", it, count));
    ASSERT_EQ(0, count);
    ASSERT_EQ(std::string::npos, it);
}

TEST_F(TestSmolFormatFixture, test_smol_detail_find_index_empty_parenthesis) {
    ASSERT_EQ(-1, smol::detail::find_index("{}", it, count));
    ASSERT_EQ(2, count);
    ASSERT_EQ(0, it);
}

TEST_F(TestSmolFormatFixture, test_smol_detail_parse_empty_parenthesis) {
    formatted = "Test 42 string";
    auto tmp = smol::format("Test {} {a}", 42, "string").get();
    ASSERT_EQ(formatted, tmp);
}

TEST_F(TestSmolFormatFixture, test_smol_detail_parse_indexed_parenthesis_more_args) {
    formatted = "Test string 42";
    ss << smol::format("Test {1} {0}", 42, "string", "test");
    ASSERT_EQ(formatted, ss.str());
}

TEST_F(TestSmolFormatFixture, test_smol_detail_parse_one_index_more_args) {
    formatted = "Test string string";
    ss << smol::format("Test {1} {}", 42, "string", "test");
    ASSERT_EQ(formatted, ss.str());
}

TEST_F(TestSmolFormatFixture, test_smol_detail_parse_3_args_all_indexed) {
    formatted = "Test string test 42 ";
    ss << smol::format("Test {1} {2} {0} {}", 42, "string", "test");
    ASSERT_EQ(formatted, ss.str());
}

TEST_F(TestSmolFormatFixture, test_smol_detail_parse_3_args_4_par_all_indexed) {
    formatted = "Test string test 42 string";
    ss << smol::format("Test {1} {2} {0} {1}", 42, "string", "test");
    ASSERT_EQ(formatted, ss.str());
}

TEST_F(TestSmolFormatFixture, test_smol_detail_parse_format_takes_no_arguments) {
    formatted = "Test 42";
    ss << smol::format("Test 42", 42, "string");
    ASSERT_EQ(ss.str(), formatted);
}

TEST_F(TestSmolFormatFixture, test_smol_detail_parse_format_wrong_index) {
    formatted = "Test string string ";
    ss << smol::format("Test {1} {3} {3}", 42, "string");
    ASSERT_EQ(ss.str(), formatted);
    std::string result = smol::format("{a}, b{}, {4}, {5}", 42, "string", 3.14); // Output to stdout string: "42, bstring, 3.140000, "
    ASSERT_EQ(result, "42, bstring, 3.140000, ");
}

int main(int _argc, char** _argv) {
    testing::InitGoogleTest(&_argc, _argv);
    return RUN_ALL_TESTS();
}
