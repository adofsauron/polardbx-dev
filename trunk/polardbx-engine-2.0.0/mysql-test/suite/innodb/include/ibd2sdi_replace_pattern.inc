# Remove number output from "last_altered" value
--let $p1=/("last_altered": )[0-9]+/\1NNN/

# Remove number output from "created" value
--let $p2=/("created": )[0-9]+/\1NNN/

# Remove se_private_data: id & trx_id output. retain the root page number value
--let $p3=/("se_private_data":) "gcn=[0-9]+;id=[0-9]+;root=[0-9]+;scn=[0-9]+;space_id=[0-9]+;table_id=[0-9]+;trx_id=[0-9]+;uba=[0-9]+;"/\1 "gcn=F;id=A;root=B;space_id=C,table_id=D,trx_id=E"/

# Remove se_private_data: id & trx_id output. retain the root page number value
--let $p4=/("se_private_data":) "id=[0-9]+;root=[0-9]+;trx_id=[0-9]+;"/\1 "id=X;root=Y;trx_id=Z"/

# Remove se_private_data: id.
--let $p5=/("se_private_data":) "id=[0-9]+;"/\1 "id=X"/

# Remove se_private_data: table_id.
--let $p6=/("se_private_data":) "table_id=[0-9]+;"/\1 "table_id=X"/

# Remove se_private_id: id. This is innodb table_id
--let $p7=/("se_private_id":) [0-9]+/\1NNN/

# Remove object_id output
--let $p8=/("id": )[0-9]+/\1X/

# Remove file_per_tablespace id output in dd::Table
--let $p9=/("tablespace_ref": "innodb_file_per_table.)[0-9]+"/\1X"/

# Remove file_per_tablespace id output in dd::Tablespace
--let p10=/("name": "innodb_file_per_table.)[0-9]+"/\1X"/

# Remove id output in se_prvate_data of dd::Tablespace
--let $p11=/("se_private_data": ")(discard=[0-1];)*(flags=)([0-9]+)(;id=)([0-9]+)(;server_version=)([0-9]+)(;space_version=)([0-9]+);/\1\3X\5Y\7Z\9M;/

# Remove version id
--let $p12=/("[a-z_]+_version_id": )[0-9]+/\1X/

# Remove extra path separator seen on windows and partition names
--let $p13=/\/\//\// /#P#/#p#/ /#SP#/#sp#/

# Remove any version id
--let $p15=/("[a-z_]+_version": )[0-9]+/\1X/

--let $ibd2sdi_pattern=$p1 $p2 $p3 $p4 $p5 $p6 $p7 $p8 $p9 $p10 $p11 $p12 $p13 $p15

# Remove se_private_data: null and table_id in dd::Column::se_private_data
--let $p16=/("se_private_data":) "default_null=[0-1];table_id=[0-9]+;"/\1 "default_null=X;table_id=Y"/

--let $ibd2sdi_pattern=$p1 $p2 $p3 $p4 $p5 $p6 $p7 $p8 $p9 $p10 $p11 $p12 $p13 $p15 $p16

# Remove root also for tables in System tablespace
--let $p3_1=/("se_private_data":) "id=[0-9]+;root=[0-9]+;space_id=[0-9]+;table_id=[0-9]+;trx_id=[0-9]+;"/\1 "id=A;root=B;space_id=C;table_id=D;trx_id=E"/

# Remove se_private_data: id & trx_id output. retain the root page number value
--let $p3_2=/("se_private_data":) "id=[0-9]+;root=[0-9]+;trx_id=[0-9]+;"/\1 "id=X;root=Y;trx_id=Z"/

# Remove se_private_data: id.
--let $p3_3=/("se_private_data":) "id=[0-9]+;"/\1 "id=X"/

# Remove se_private_data: table_id.
--let $p3_4=/("se_private_data":) "table_id=[0-9]+;"/\1 "table_id=X"/

--let $ibd2sdi_pattern_system=$p1 $p2 $p3_1 $p3_2 $p3_3 $p3_4 $p4 $p5 $p6 $p7 $p8 $p9 $p10 $p11 $p12 $p13 $p15 $p16

# Remove collation_id only for dictionary tables
--let $p15=/("collation_id": )[0-9]+/\1X/

--let $ibd2sdi_pattern_mysql= $ibd2sdi_pattern $p15
