.\winrel\edit_source -configure
.\winrel\edit_source -options -process grammar.y.pre -malloc -build_func_spec "cl /E" -build_efuns

ren efun_protos.h efun_tmp.h
sed -f sed.cmd efun_tmp.h > efun_protos.h

