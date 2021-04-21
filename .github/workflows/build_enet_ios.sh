#!/bin/sh
#set -eo pipefail
set -e

rtt=$(git describe --tags `git rev-list --tags --max-count=1`)
rc=$(git rev-parse --short HEAD)
rb=$(git rev-parse --abbrev-ref HEAD)
rbb=$(git symbolic-ref --short -q HEAD)
rbbb=$(git branch --contains $rtt | grep '*')
echo $rc
echo $rb
echo $rbb
echo $rbbb
