/*
 *
 *  $Id$
 *
 *  This file is part of the Virtual Leaf.
 *
 *  The Virtual Leaf is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  The Virtual Leaf is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with the Virtual Leaf.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Copyright 2010 Roeland Merks.
 *
 */

#ifndef _PARAMETER_H_
#define _PARAMETER_H_
#include "vector.h"
#include <vector>

#include <libxml/parser.h>
#include <libxml/tree.h>

class Parameter {
  
 public: 
  Parameter();
  ~Parameter();
  void CleanUp(void);
  void Read(const char *filename);
  void Write(ostream &os) const;
  void XMLAdd(xmlNode *root) const;
  void XMLRead(xmlNode *root);
  void AssignValToPar(const char *namec, const char *valc);
  void AssignValArrayToPar(const char *namec, vector<double> valarray);
  char * arrowcolor;
  double arrowsize;
  char * textcolor;
  int cellnumsize;
  int nodenumsize;
  double node_mag;
  double outlinewidth;
  char * cell_outline_color;
  int resize_stride;
  double T;
  double lambda_length;
  double lambda_celllength;
  double target_length;
  double cell_expansion_rate;
  double cell_div_expansion_rate;
  bool auxin_dependent_growth;
  double ode_accuracy;
  double mc_stepsize;
  double mc_cell_stepsize;
  double energy_threshold;
  double bend_lambda;
  double alignment_lambda;
  double rel_cell_div_threshold;
  double rel_perimeter_stiffness;
  double collapse_node_threshold;
  double morphogen_div_threshold;
  double morphogen_expansion_threshold;
  bool copy_wall;
  double source;
  double * D;
  double * initval;
  double k1;
  double k2;
  double r;
  double kr;
  double km;
  double Pi_tot;
  double transport;
  double ka;
  double pin_prod;
  double pin_prod_in_epidermis;
  double pin_breakdown;
  double pin_breakdown_internal;
  double aux1prod;
  double aux1prodmeso;
  double aux1decay;
  double aux1decaymeso;
  double aux1transport;
  double aux_cons;
  double aux_breakdown;
  double kaux1;
  double kap;
  double leaf_tip_source;
  double sam_efflux;
  double sam_auxin;
  double sam_auxin_breakdown;
  double van3prod;
  double van3autokat;
  double van3sat;
  double k2van3;
  double dt;
  double rd_dt;
  char * datadir;
  bool movie;
  int nit;
  double maxt;
  int storage_stride;
  int xml_storage_stride;
  int rseed;
  int constituous_expansion_limit;
  double vessel_inh_level;
  double vessel_expansion_rate;
  double d;
  double e;
  double f;
  double c;
  double mu;
  double nu;
  double rho0;
  double rho1;
  double c0;
  double gamma;
  double eps;
  double * k;
  int i1;
  int i2;
  int i3;
  int i4;
  int i5;
  char * s1;
  char * s2;
  char * s3;
  bool b1;
  bool b2;
  bool b3;
  bool b4;
  char * dir1;
  char * dir2;
 private:
};

ostream &operator<<(ostream &os, Parameter &p);
const char *sbool(const bool &p);


#endif