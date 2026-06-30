#pragma once
#include <fstream>
#include <string>

class TreeVisualizer {
private:
  template<typename NodeType>
  static void generateDotAux(NodeType* node,
                             std::ofstream& file){

    if(!node) return;

    if(node->left){
      file << node->data
           << " -> "
           << node->left->data
           << ";\n";
    }

    if(node->right){
      file << node->data
           << " -> "
           << node->right->data
           << ";\n";
    }

    generateDotAux(node->left, file);
    generateDotAux(node->right, file);
  }

public:

  template<typename NodeType>
  static void generate(NodeType* root,
                       const std::string& filename){

    std::ofstream file(filename);

    file << "digraph G {\n";
    generateDotAux(root, file);
    file << "}\n";
  }
};
