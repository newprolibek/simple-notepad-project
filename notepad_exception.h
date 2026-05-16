#ifndef NOTEPAD_EXCEPTION_H
#define NOTEPAD_EXCEPTION_H

#include <stdexcept>

class notepad_exception : public std::runtime_error {
public:
    explicit notepad_exception(const std::string& message)
        : std::runtime_error(message)
    {
    }
};

class file_not_found_exception : public notepad_exception {
public:
    explicit file_not_found_exception(const std::string& file)
        : notepad_exception("File not found: '" + file + "'")
    {
    }
};

class file_read_exception : public notepad_exception {
public:
    explicit file_read_exception(const std::string& file)
        : notepad_exception("Failed to read file: '" + file + "'")
    {
    }
};

class file_write_exception : public notepad_exception {
public:
    explicit file_write_exception(const std::string& file)
        : notepad_exception("Failed to write file: '" + file + "'")
    {
    }
};

#endif // NOTEPAD_EXCEPTION_H
