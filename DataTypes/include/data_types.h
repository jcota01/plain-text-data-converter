/**
 * @file data_types.h
 * @author Jack Cota
 *
 * @brief Contains the declarations for the generic data types used by the data formats.
 *
 * This header file contains the base class for data types, DataNode, as well as all the specific derived data types,
 * as well as their function and member declarations.
 */

#ifndef TEXT_DATA_CONVERTER_DATA_TYPES_H
#define TEXT_DATA_CONVERTER_DATA_TYPES_H

#include <string>
#include <memory>
#include <vector>
#include <utility>
#include <stdexcept>

/**
 * @brief Enumerates each data type
 *
 * This is used when the derived objects are stored as a base DataNode object, so that the derived type can be determined
 * and then the object can be cast back into its derived type.
 */
enum class DataType{
    STRING,
    NUMBER,
    OBJECT,
    LIST,
    NULL_TYPE,
    BOOL
};

/**
 * @brief Base abstract class for each data type
 *
 * This is the base abstract class that all other data type classes derive from. This class stores the name and data type
 * of the node, as well as defining some basic functions such as getType() and setName(), as well as declaring the abstract
 * function toString().\n\n
 *
 * By making each data type class inherit this abstract class, it means that we can generically refer to a specific
 * data node object, and create collections of data nodes of different types.
 */
class DataNode{
public:
    /**
     * @brief Get the specific data type of the node.
     * @return DataType enum representing the node's data type
     */
    [[nodiscard]] DataType getType() const noexcept;

    /**
     * @brief Converts the data node to a string for outputting.
     *
     * This is a pure virtual function and is therefore overridden by the derived classes as they require their own
     * implementations based on the data type they are storing.
     *
     * @return String representation of the data node
     */
    [[nodiscard]] virtual std::string toString() = 0;

    /**
     * @brief Sets the class property "name"
     * @param n  The new value of property "name"
     */
    void setName(std::string&& n);

    /**
     * @brief Default virtual destructor
     */
    virtual ~DataNode() = default;

protected:
    /**
     * @brief Constructor for the DataNode object
     *
     * This constructor is protected so that it cannot be used outside of class member functions of DataNode itself
     * or derived classes.
     *
     * @param nodeName  Name of the node
     * @param dataType  Data type of the node
     */
    explicit DataNode(std::string&& nodeName, DataType dataType);

    /**
     * @brief Returns the name of the node
     *
     * If the node has a name, it returns it in the format "NAME : " for JSON style formatting of the output, whereby
     * the value of the node will follow.\n\n
     *
     * If the node has no name (name == ""), then "" is returned.\n
     *
     * @return String name of the node
     */
    std::string nameToString();

private:
    /**
     * Name of the node.
     *
     * For example, in JSON, the name is the key in a key value pair, such as "personName": "Jack".\n
     * In this example, "personName" would be the value stored in this name property.
     */
    std::string name;

    /// Data type of the node
    DataType type;
};


/**
 * @brief Represents a data node holding a string value.
 */
class String : public DataNode{
public:
    /**
     * @brief Public factory function used to create a String object.
     *
     * This static function is preferred over the constructor so that the object can be wrapped within a unique pointer,
     * hiding any naked pointers from the user and thereby eliminating the risk of a memory leak.
     *
     * @param nodeName  Name of the node
     * @return  A new String object wrapped in a unique pointer
     */
    static std::unique_ptr<String> create(std::string&& nodeName);

    /**
     * @brief Converts the string data node to a string for outputting
     *
     * This function is an override of the DataNode toString() function
     *
     * @return String representation of the string data node
     */
    [[nodiscard]] std::string toString() override;

    /**
     * @brief Sets the string value held by the object
     * @param val  String value to store within the object
     */
    void set(std::string&& val);

protected:
    /**
     * @brief Constructor for the String object
     *
     * The constructor is protected so that objects can only be instantiated wrapped within a unique pointer, to help
     * prevent memory leaks.
     *
     * @param nodeName  Name of the string data node
     */
    explicit String(std::string&& nodeName);

private:
    /**
     * String value of the node.
     */
    std::unique_ptr<std::string> value;
};


/**
 * @brief Represents a data node holding a numerical value.
 */
class Number : public DataNode{
public:
    /**
     * Public factory function used to create a Number object.
     *
     * This static function is preferred over the constructor so that the object can be wrapped within a unique pointer,
     * hiding any naked pointers from the user and thereby eliminating the risk of a memory leak.
     *
     * @param nodeName  Name of the node
     * @param num  Numerical value to store within the data node
     * @return  A new Number object wrapped in a unique pointer
     */
    static std::unique_ptr<Number> create(std::string&& nodeName, int num);

    /**
     * @brief Converts the number data node to a string for outputting
     *
     * This function is an override of the DataNode toString() function
     *
     * @return String representation of the number data node
     */
    [[nodiscard]] std::string toString() override;

protected:
    /**
     * @brief Constructor for the Number object
     *
     * The constructor is protected so that objects can only be instantiated wrapped within a unique pointer, to help
     * prevent memory leaks.
     *
     * @param nodeName  Name of the Number data node
     * @param num  Numerical value to store within the data node
     */
    explicit Number(std::string&& nodeName, int num);

private:
    /// Numerical value of the data node
    int value;
};


/**
 * @brief Represents a data node which itself represents an object.
 *
 * This object is used to store data in formats such as a JSON object. This means that this Object node can store
 * child nodes of any of the derived DataNode classes.
 */
class Object : public DataNode{
public:
    /**
     * Public factory function used to create an Object object.
     *
     * This static function is preferred over the constructor so that the object can be wrapped within a unique pointer,
     * hiding any naked pointers from the user and thereby eliminating the risk of a memory leak.
     *
     * @param nodeName  Name of the node
     * @return  A new Object wrapped in a unique pointer
     */
    static std::unique_ptr<Object> create(std::string&& nodeName);

    /**
     * @brief Adds a child data node to this node.
     * @param node  Child node to be added to this node
     */
    void addChild(std::unique_ptr<DataNode>&& node);

    /**
     * @brief Converts the Object data node to a string for outputting
     *
     * This function is an override of the DataNode toString() function
     *
     * @return String representation of the Object data node
     */
    [[nodiscard]] std::string toString() override;

protected:
    /**
     * @brief Constructor for the Object object
     *
     * The constructor is protected so that objects can only be instantiated wrapped within a unique pointer, to help
     * prevent memory leaks.
     *
     * @param nodeName  Name of the Object data node
     */
    explicit Object(std::string&& nodeName);

private:
    /**
     * @brief Stores all the child data nodes of this node.
     *
     * Each child node is stored as a unique pointer, and therefore they are owned by this object. Once this object is
     * destroyed, the child nodes are also automatically destroyed too, avoiding the risk of any orphan nodes and
     * therefore memory leaks.
     */
    std::vector<std::unique_ptr<DataNode>> values;
};


/**
 * @brief Represents a data node which can store an array of values.
 *
 * The List stores the collection of values as individual DataNodes, however these nodes do not have names, just as an
 * array in JSON does not have names for each value in the array.\n\name
 *
 * e.g. "array": [1, "hello", {"test": "apples"}]
 */
class List : public DataNode{
public:
    /**
     * Public factory function used to create a List object.
     *
     * This static function is preferred over the constructor so that the object can be wrapped within a unique pointer,
     * hiding any naked pointers from the user and thereby eliminating the risk of a memory leak.
     *
     * @param nodeName  Name of the node
     * @return  A new List wrapped in a unique pointer
     */
    static std::unique_ptr<List> create(std::string&& nodeName);

    /**
     * @brief Adds a data node to this node's array.
     * @param node  Node to be added to the array
     */
    void addChild(std::unique_ptr<DataNode>&& node);

    /**
     * @return Size of the array stored by this node
     */
    size_t size();

    /**
     * @brief Returns a specific element in the array
     *
     * This function overrides the [] operator so that the elements of the array stored within this object can be indexed
     * directly from the object.\n\n
     *
     * This function throws an out of range error if there is not an element at the entered index.
     *
     * @param index  Numerical index of the desired node in the array
     * @return  Node stored at that index
     */
    DataNode& operator[](int index);

    /**
     * @brief Converts the List data node to a string for outputting
     *
     * This function is an override of the DataNode toString() function
     *
     * @return String representation of the List data node
     */
    [[nodiscard]]std::string toString() override;

protected:
    /**
     * @brief Constructor for the List object
     *
     * The constructor is protected so that objects can only be instantiated wrapped within a unique pointer, to help
     * prevent memory leaks.
     *
     * @param nodeName  Name of the List data node
     */
    explicit List(std::string&& nodeName);

private:
    /**
     * @brief Stores all the nodes in the array
     *
     * Each node is stored as a unique pointer, and therefore they are owned by this object. Once this object is
     * destroyed, the nodes in the array are also automatically destroyed too, avoiding the risk of any orphan nodes and
     * therefore memory leaks.
     */
    std::vector<std::unique_ptr<DataNode>> values;
};


/**
 * @brief Represents a data node storing a null value
 */
class Null : public DataNode{
public:
    /**
     * Public factory function used to create a Null object.
     *
     * This static function is preferred over the constructor so that the object can be wrapped within a unique pointer,
     * hiding any naked pointers from the user and thereby eliminating the risk of a memory leak.
     *
     * @param nodeName  Name of the node
     * @return  A new Null wrapped in a unique pointer
     */
    static std::unique_ptr<Null> create(std::string&& nodeName);

    /**
     * @brief Converts the Null data node to a string for outputting
     *
     * This function is an override of the DataNode toString() function
     *
     * @return String representation of the Null data node
     */
    [[nodiscard]]std::string toString() override;

protected:
    /**
     * @brief Constructor for the Null object
     *
     * The constructor is protected so that objects can only be instantiated wrapped within a unique pointer, to help
     * prevent memory leaks.
     *
     * @param nodeName  Name of the Null data node
     */
    explicit Null(std::string&& nodeName);
};


/**
 * @brief Represents a data node storing a boolean value
 */
class Bool : public DataNode{
public:
    /**
     * Public factory function used to create a Bool object.
     *
     * This static function is preferred over the constructor so that the object can be wrapped within a unique pointer,
     * hiding any naked pointers from the user and thereby eliminating the risk of a memory leak.
     *
     * @param nodeName  Name of the node
     * @param val  bool value to store in the node
     * @return  A new Bool object wrapped in a unique pointer
     */
    static std::unique_ptr<Bool> create(std::string&& nodeName, bool val);

    /**
     * @brief Converts the Bool data node to a string for outputting
     *
     * This function is an override of the DataNode toString() function
     *
     * @return String representation of the Bool data node
     */
    [[nodiscard]]std::string toString() override;

    /**
     * @brief Sets the boolean value
     * @param val  New bool value
     */
    void set(bool val);

protected:
    /**
     * @brief Constructor for the Bool object
     *
     * The constructor is protected so that objects can only be instantiated wrapped within a unique pointer, to help
     * prevent memory leaks.
     *
     * @param nodeName  Name of the Bool data node
     * @param val  Bool value to store
     */
    explicit Bool(std::string&& nodeName, bool val);

private:
    /// Bool value stored by the data node
    bool value;
};

#endif //TEXT_DATA_CONVERTER_DATA_TYPES_H
