#include <pgf/gd/interface/c/InterfaceFromC.h>

#include <math.h>

static void fast_hello_world (pgfgd_SyntacticDigraph* graph) {
  double angle  = 6.28318530718 / graph->vertices.length;
  double radius = pgfgd_tonumber(graph->options, "my radius");
  
  int i;
  for (i = 0; i < graph->vertices.length; i++) {
    pgfgd_Vertex* v = graph->vertices.array[i];
    v->pos.x = cos(angle*i) * radius;
    v->pos.y = sin(angle*i) * radius;
  }
}


int luaopen_pgf_gd_examples_c_FastSimpleDemo (struct lua_State *state) {
  
  {
    // The main layout key
    pgfgd_Declaration* d = pgfgd_new_key (state, "fast simple demo layout");
    pgfgd_key_summary          (d, "The C version of the hello world of graph drawing");
    pgfgd_key_algorithm        (d, fast_hello_world);
    pgfgd_key_add_precondition (d, "connected");
    pgfgd_declare              (d);
  }

  {
    // The radius key
    pgfgd_Declaration* d = pgfgd_new_key (state, "my radius");
    pgfgd_key_summary (d, "A radius value for the hello world of graph drawing");
    pgfgd_key_type    (d, "length");
    pgfgd_key_initial (d, "1cm");
    pgfgd_key_add_use (d, "radius", "1cm");
    pgfgd_key_add_use (d, "radius", "2cm");
    pgfgd_declare     (d);
  }
  
  return 0;
}
