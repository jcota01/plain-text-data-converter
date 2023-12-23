//
// Created by 01jac on 23/12/2023.
//

#ifndef TEXT_DATA_CONVERTER_DATA_TYPES_H
#define TEXT_DATA_CONVERTER_DATA_TYPES_H

#include <string>
#include <memory>
#include <vector>

class DataNode{
public:
    [[nodiscard]] virtual std::string toString() const = 0;
};


class String : public DataNode{
public:
    explicit String(const std::string& val);
    String();

    [[nodiscard]] std::string toString() const override;

    void set(const std::string& val);

private:
    std::unique_ptr<std::string> value;
};


class Number : public DataNode{
public:
    explicit Number(int num);

    [[nodiscard]] std::string toString() const override;

private:
    int value;
};


class Object : public DataNode{
public:
    explicit Object(DataNode* obj);
    Object();

    void setChild(DataNode* obj);

    [[nodiscard]] std::string toString() const override;

private:
    DataNode* value;
};


class List : public DataNode{
public:
    void addChild(DataNode* node);

    size_t size();

    DataNode& operator[](int index);

    [[nodiscard]]std::string toString() const override;

private:
    std::vector<DataNode*> values;
};

#endif //TEXT_DATA_CONVERTER_DATA_TYPES_H
