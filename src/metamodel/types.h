#pragma once

#include "tools/countable.h"

#include "metamodel/modular.h"

namespace abject {
class ArrayModel;

/**
*@brief The Artefact class
*Artefact is something like "Object" for OOP language.
*/
class Artefact : public Modular, public Countable {
 public:
  Artefact(Module *module);
  virtual ~Artefact();

 private:
};

/**
 * @brief The Model class
 * A model is something like "Class" for OOP language.
 */
class Model : public Artefact {
 public:
  Model(Module *module);
  virtual ~Model();

  ArrayModel *ArrayOf();

 private:
};

class Facet : public Model {
 public:
  Facet(Module *module);
  virtual ~Facet();

 private:
};

class ArrayModel : public Model {
 public:
  Model *of() const;

  ~ArrayModel();

 private:
  ArrayModel(Model *of);

  cref<Model> of_;

  friend class Model;
};

// Primitive bellow
class String : public Model {
 public:
  static String *Instance();
  virtual ~String();

 private:
  String();
};

}  // namespace abject
