#pragma once
#include "json.h"

#include <optional>
#include <string_view>
#include <vector>

namespace json {

class Builder {
public:
    Builder& Value(Node::Value value);

    Builder& StartDict();
    Builder& Key(std::string key);
    Builder& EndDict();

    Builder& StartArray();
    Builder& EndArray();

    Node Build();

private:
    std::optional<Node> root_;

    bool isBuilt = false;

    std::vector<Node*> nodes_stack_;
};

} // namespace json
