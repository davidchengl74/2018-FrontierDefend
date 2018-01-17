#!/bin/sh

#  build_meta.sh
#  PineEntertainment
#
#  Created by Do Thanh Nghia on 6/12/14.
#

#echo "Hello world!"
current_dir=$(pwd -L)
odata_gen_tool=$current_dir"/src/game/mac_core/ODataSDK/Framework/bin/OdatagenBinary"
odata_gen_meta=$current_dir"/doc/metadata.xml"
odata_gen_output=$current_dir"/src/_mac/src/PineGame/Classes"
echo $current_dir
echo $odata_gen_tool
echo $odata_gen_meta
echo $odata_gen_output

cd $odata_gen_tool
chmod +x ./odatagen
#sudo ./odatagen

sudo ./odatagen /metadata=$odata_gen_meta /out=$odata_gen_output
#echo sudo ./odatagen /metadata=$odata_gen_meta /out=./
cd $current_dir

