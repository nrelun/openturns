//                                               -*- C++ -*-
/**
 *  @brief An implementation from samples
 *
 *  Copyright 2005-2018 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_INVERSEDISTANCEWEIGHTINGINTERPOLATION_HXX
#define OPENTURNS_INVERSEDISTANCEWEIGHTINGINTERPOLATION_HXX

#include "openturns/EvaluationImplementation.hxx"
#include "openturns/Collection.hxx"
#include "openturns/PersistentCollection.hxx"
#include "openturns/NearestNeighbourAlgorithm.hxx"

BEGIN_NAMESPACE_OPENTURNS


/**
 * @class InverseDistanceWeightingInterpolation
 * Provided two samples X (input) and Y (output), returns Yi when evaluated on Xi.
 */
class OT_API InverseDistanceWeightingInterpolation
  : public EvaluationImplementation
{
  CLASSNAME
  friend class FunctionImplementation;

public:

  /** Default constructor */
  InverseDistanceWeightingInterpolation();

  /** Default constructor */
  InverseDistanceWeightingInterpolation(const Sample & inputSample,
                     const Sample & outputSample, const Scalar &p);

  /** Virtual constructor */
  virtual InverseDistanceWeightingInterpolation * clone() const;

  /** Comparison operator */
  Bool operator ==(const InverseDistanceWeightingInterpolation & other) const;

  /** String converter */
  String __repr__() const;
  String __str__( const String & offset = "" ) const;

  /** Input sample accessor */
  void setInputSample(const Sample & inputSample);
  Sample getInputSample() const;

  /** Output sample accessor */
  void setOutputSample(const Sample & outputSample);
  Sample getOutputSample() const;

  /**Smoothing parmater p */
  Scalar getP() const; 

  /** Nearest neighbour algorithm accessor */
  NearestNeighbourAlgorithm getNearestNeighbourAlgorithm() const;
  void setNearestNeighbourAlgorithm(const NearestNeighbourAlgorithm & tree);

  /* Here is the interface that all derived class must implement */

  /** Operator () */
  virtual Point operator()(const Point & inP) const;
  virtual Sample operator()(const Sample & inS) const;

  /** Accessor for input point dimension */
  virtual UnsignedInteger getInputDimension() const;

  /** Accessor for output point dimension */
  virtual UnsignedInteger getOutputDimension() const;

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv);


protected:
  /** Set cached sample */
  void setSample(const Sample & inputSample,
                 const Sample & outputSample);
  void setP(const Scalar & p);

  Sample inputSample_;
  Sample outputSample_;
  NearestNeighbourAlgorithm nearestNeighbour_;
  Scalar p_;
  String norm_;
private:


}; /* class InverseDistanceWeightingInterpolation */


END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_InverseDistanceWeightingInterpolation_HXX */
