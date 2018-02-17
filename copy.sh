echo "Renaming..."
mv out/Download/flash/kernel_lenovo77_s720.bin boot.img-kernel
#mv out/Download/flash/kernel_lenovo77_s720.bin recovery.img-kernel
echo "Moving..."
mv -u boot.img-kernel ~/CarlivImageKitchen64/boot/
#mv -u recovery.img-kernel ~/CarlivImageKitchen64/recovery/
echo " "