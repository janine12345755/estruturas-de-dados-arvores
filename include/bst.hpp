#pragma once
#include <utility>
#include <vector>

/**
 * @brief Classe que representa uma Árvore Binária de Busca (BST).
 *
 * Armazena elementos em ordem, permitindo operações eficientes de busca,
 * inserção e remoção.
 *
 * @tparam T Tipo dos elementos armazenados na árvore.
 */
template <class T>
class BST {
 public:
  /**
   * @brief Estrutura interna que representa um nó da árvore.
   */
  struct TreeNode {
    T data;           ///< Valor armazenado no nó.
    TreeNode* left;   ///< Ponteiro para o filho à esquerda.
    TreeNode* right;  ///< Ponteiro para o filho à direita.

    /**
     * @brief Construtor que inicializa o nó com um valor.
     *
     * @param value Valor a ser armazenado no nó.
     */
    TreeNode(const T& value);

    /**
     * @brief Destrutor do nó, libera recursivamente seus filhos.
     */
    ~TreeNode();

    /**
     * @brief Retorna o nó com o maior valor da subárvore.
     *
     * @return Ponteiro para o nó com o valor máximo.
     */
    TreeNode* max();

    /**
     * @brief Retorna o nó com o menor valor da subárvore.
     *
     * @return Ponteiro para o nó com o valor mínimo.
     */
    TreeNode* min();
  };

 private:
  /**
   * @brief Insere um valor na árvore recursivamente.
   *
   * @param node Ponteiro de referência para o nó atual.
   * @param value Valor a ser inserido.
   * @return `true` se a inserção foi bem-sucedida, `false` se o valor já
   * existia.
   */
  bool insert(TreeNode*& node, const T& value);

  /**
   * @brief Remove um valor da árvore recursivamente.
   *
   * @param node Ponteiro de referência para o nó atual.
   * @param value Valor a ser removido.
   * @return `true` se a remoção foi bem-sucedida, `false` se o valor não foi
   * encontrado.
   */
  bool remove(TreeNode*& node, const T& value);

  /**
   * @brief Verifica se a árvore contém um valor específico.
   *
   * @param node Ponteiro para o nó atual.
   * @param value Valor a ser buscado.
   * @return `true` se o valor estiver na árvore, `false` caso contrário.
   */
  bool contain(const TreeNode* const node, const T& value) const;

  /**
   * @brief Executa a travessia in-order recursiva.
   *
   * Visita a subárvore esquerda, depois o nó atual e em seguida a subárvore
   * direita. Os valores visitados são armazenados em `result`.
   *
   * @param node Ponteiro para o nó atual.
   * @param result Vetor onde os valores visitados serão armazenados.
   */
  void in_order(const TreeNode* const node, std::vector<T>& result) const;

  /**
   * @brief Executa a travessia pre-order recursiva.
   *
   * Visita o nó atual, em seguida a subárvore esquerda e depois a direita.
   * Os valores visitados são armazenados em `result`.
   *
   * @param node Ponteiro para o nó atual.
   * @param result Vetor onde os valores visitados serão armazenados.
   */
  void pre_order(const TreeNode* const node, std::vector<T>& result) const;

  /**
   * @brief Executa a travessia post-order recursiva.
   *
   * Visita a subárvore esquerda, depois a direita e por último o nó atual.
   * Os valores visitados são armazenados em `result`.
   *
   * @param node Ponteiro para o nó atual.
   * @param result Vetor onde os valores visitados serão armazenados.
   */
  void post_order(const TreeNode* const node, std::vector<T>& result) const;

  TreeNode* find_node(TreeNode* node, const T& value) const {
    if (node == nullptr) {
      return nullptr;
    }

    if (value < node->data) {
      return find_node(node->left, value);
    } else if (node->data < value) {
      return find_node(node->right, value);
    } else {
      return node;
    }
  }

 public:
  /**
   * @brief Construtor da árvore (inicialmente vazia).
   */
  BST();

  /**
   * @brief Destrutor da árvore, libera todos os nós.
   */
  ~BST();

  /**
   * @brief Insere um novo valor na árvore.
   *
   * @param value Valor a ser inserido.
   * @return `true` se inserido com sucesso, `false` se o valor já existia.
   */
  bool insert(const T& value);

  /**
   * @brief Remove um valor da árvore.
   *
   * @param value Valor a ser removido.
   * @return `true` se o valor foi removido, `false` se não estava presente.
   */
  bool remove(const T& value);

  /**
   * @brief Verifica se um valor está presente na árvore.
   *
   * @param value Valor a ser verificado.
   * @return `true` se presente, `false` caso contrário.
   */
  bool contain(const T& value) const;

  /**
   * @brief Retorna os valores da árvore em ordem (in-order).
   *
   * Visita a subárvore esquerda, o nó atual e a subárvore direita.
   *
   * @return Vetor com os valores em ordem.
   */
  std::vector<T> in_order() const;

  /**
   * @brief Retorna os valores da árvore em pré-ordem (pre-order).
   *
   * Visita o nó atual, depois a subárvore esquerda e depois a direita.
   *
   * @return Vetor com os valores em pré-ordem.
   */
  std::vector<T> pre_order() const;

  /**
   * @brief Retorna os valores da árvore em pós-ordem (post-order).
   *
   * Visita a subárvore esquerda, depois a direita e por fim o nó atual.
   *
   * @return Vetor com os valores em pós-ordem.
   */
  std::vector<T> post_order() const;

  /**
   * @brief Retorna o ponteiro para o nodo contendo o valor.
   *
   * @return Ponteiro para o nodo ou nullptr se o valor não estiver na árvore.
   */
  TreeNode* find_node(const T& value) const { return find_node(root, value); }

 private:
  TreeNode* root;  ///< Ponteiro para a raiz da árvore.
};

template <class T>
BST<T>::TreeNode::TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}

template <class T>
BST<T>::TreeNode::~TreeNode() {
    delete left;
    delete right;
}

template <class T>
typename BST<T>::TreeNode* BST<T>::TreeNode::max() {
    TreeNode* current = this;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}

template <class T>
typename BST<T>::TreeNode* BST<T>::TreeNode::min() {
    TreeNode* current = this;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

template <class T>
BST<T>::BST() : root(nullptr) {}

template <class T>
BST<T>::~BST() {
    delete root;
}

template <class T>
bool BST<T>::insert(const T& value) {
    return insert(root, value);
}

template <class T>
bool BST<T>::remove(const T& value) {
    return remove(root, value);
}

template <class T>
bool BST<T>::contain(const T& value) const {
    return contain(root, value);
}

template <class T>
bool BST<T>::insert(TreeNode*& node, const T& value) {
    if (node == nullptr) {
        node = new TreeNode(value);
        return true;
    }

    if (value < node->data) {
        return insert(node->left, value);
    } else if (node->data < value) {
        return insert(node->right, value);
    } else {
        return false;
    }
}

template <class T>
bool BST<T>::contain(const TreeNode* const node, const T& value) const {
    if (node == nullptr) 
     return false;

    if (value < node->data) {
        return contain(node->left, value);
    } else if (node->data < value) {
        return contain(node->right, value);
    } else {
        return true;
    }
}

template <class T>
bool BST<T>::remove(TreeNode*& node, const T& value) {
    if (node == nullptr) 
    return false;

    if (value < node->data) {
        return remove(node->left, value);
    } else if (node->data < value) {
        return remove(node->right, value);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            TreeNode* toDelete = node;
            node = node->right;
            toDelete->left = nullptr;
            toDelete->right = nullptr;
            delete toDelete;
        } else if (node->right == nullptr) {
            TreeNode* toDelete = node;
            node = node->left;
            toDelete->left = nullptr;
            toDelete->right = nullptr;
            delete toDelete;
        } else {
            TreeNode* successor = node->right->min();
            node->data = successor->data;
            return remove(node->right, successor->data);
        }
        return true;
    }
}

template <class T>
void BST<T>::in_order(const TreeNode* const node, std::vector<T>& result) const {
    if (node == nullptr) return;
    in_order(node->left, result);
    result.push_back(node->data);
    in_order(node->right, result);
}

template <class T>
std::vector<T> BST<T>::in_order() const {
    std::vector<T> result;
    in_order(root, result);
    return result;
}

template <class T>
void BST<T>::pre_order(const TreeNode* const node, std::vector<T>& result) const {
    if (node == nullptr) return;
    result.push_back(node->data);
    pre_order(node->left, result);
    pre_order(node->right, result);
}

template <class T>
std::vector<T> BST<T>::pre_order() const {
    std::vector<T> result;
    pre_order(root, result);
    return result;
}

template <class T>
void BST<T>::post_order(const TreeNode* const node, std::vector<T>& result) const {
    if (node == nullptr) return;
    post_order(node->left, result);
    post_order(node->right, result);
    result.push_back(node->data);
}

template <class T>
std::vector<T> BST<T>::post_order() const {
    std::vector<T> result;
    post_order(root, result);
    return result;
}
