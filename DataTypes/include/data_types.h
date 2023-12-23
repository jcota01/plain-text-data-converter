//
// Created by 01jac on 23/12/2023.
//

#ifndef TEXT_DATA_CONVERTER_DATA_TYPES_H
#define TEXT_DATA_CONVERTER_DATA_TYPES_H

#include <string>
#include <memory>
#include <vector>

/**
 * Generic abstract data node which is inherited by each data type
 */
class DataNode{
public:
    explicit DataNode(std::string nodeName="");

    [[nodiscard]] virtual std::string toString() = 0;

    void setName(std::string n);

protected:
    std::string nameToString();

private:
    std::string name;
};


/**
 * Class representing a string object in the data.
 */
class String : public DataNode{
public:
    explicit String(const std::string& val, std::string nodeName="");
    String(std::string nodeName="");

    [[nodiscard]] std::string toString() override;

    void set(const std::string& val);

private:
    std::unique_ptr<std::string> value;
};


class Number : public DataNode{
public:
    explicit Number(int num, std::string nodeName="");

    [[nodiscard]] std::string toString() override;

private:
    int value;
};


class Object : public DataNode{
public:
    explicit Object(DataNode* obj, std::string nodeName="");
    explicit Object(std::string nodeName="");

    void addChild(DataNode* obj);

    [[nodiscard]] std::string toString() override;

private:
    std::vector<DataNode*> values;
};


class List : public DataNode{
public:
    List(std::string nodeName="");

    void addChild(DataNode* node);

    size_t size();

    DataNode& operator[](int index);

    [[nodiscard]]std::string toString() override;

private:
    std::vector<DataNode*> values;
};

#endif //TEXT_DATA_CONVERTER_DATA_TYPES_H
