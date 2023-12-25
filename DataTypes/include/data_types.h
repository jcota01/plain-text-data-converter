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
    [[nodiscard]] virtual std::string toString() = 0;

    void setName(std::string n);

    virtual ~DataNode() = default;

protected:
    explicit DataNode(std::string nodeName);

    std::string nameToString();

private:
    std::string name;
};


/**
 * Class representing a string object in the data.
 */
class String : public DataNode{
public:
    static std::unique_ptr<String> create(std::string nodeName);

    [[nodiscard]] std::string toString() override;

    void set(const std::string& val);

protected:
    explicit String(std::string nodeName);


private:
    std::unique_ptr<std::string> value;
};


class Number : public DataNode{
public:
    static std::unique_ptr<Number> create(std::string nodeName, int num);

    [[nodiscard]] std::string toString() override;

protected:
    explicit Number(std::string nodeName, int num);

private:
    int value;
};


class Object : public DataNode{
public:
    static std::unique_ptr<Object> create(std::string nodeName);

    void addChild(std::unique_ptr<DataNode>&& node);

    [[nodiscard]] std::string toString() override;

protected:
    explicit Object(std::string nodeName);

private:
    std::vector<std::unique_ptr<DataNode>> values;
};


class List : public DataNode{
public:
    static std::unique_ptr<List> create(std::string nodeName);

    void addChild(std::unique_ptr<DataNode>&& node);

    size_t size();

    DataNode& operator[](int index);

    [[nodiscard]]std::string toString() override;

protected:
    explicit List(std::string nodeName);

private:
    std::vector<std::unique_ptr<DataNode>> values;
};

#endif //TEXT_DATA_CONVERTER_DATA_TYPES_H
