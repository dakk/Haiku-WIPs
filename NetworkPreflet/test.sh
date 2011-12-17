rm -r /boot/home/haiku/src/preferences/network
cp -r network /boot/home/haiku/src/preferences/
cd /boot/home/haiku/src/preferences/network
rm /boot/home/haiku/generated/objects/haiku/x86/release/preferences/network/*
jam
/boot/home/haiku/generated/objects/haiku/x86/release/preferences/network/Network
