#pragma once
#include <fstream>
#include <string>

class TreeVisualizer {
private:
  template<typename NodeType>
 static void generateDotAux(NodeType* node,
                           std::ofstream& file){
  if(!node) return;
  static int nullCount = 0;

  // Hijo izquierdo
  if(node->left){
    file << node->data
         << " -> "
         << node->left->data
         << ";\n";
  }else{
    file << "null" << nullCount
         << " [shape=point];\n";
    file << node->data
         << " -> null" << nullCount++
         << ";\n";
  }
  // Hijo derecho
  if(node->right){
    file << node->data
         << " -> "
         << node->right->data
         << ";\n";
  }else{
    file << "null" << nullCount
         << " [shape=point];\n";
    file << node->data
         << " -> null" << nullCount++
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
