#!/bin/bash

cd polardbx-engine-2.0.0

chmod +x storage/xengine/*.sh

bash ./build.sh -t debug

cd -
