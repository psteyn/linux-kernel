--- drivers/net/cris/eth_v10.c 2008-06-12 14:12:33.000000000 +0200
+++ drivers/net/cris/eth_v10.c 2008-06-12 14:19:35.000000000 +0200
@@ -1430,7 +1430,11 @@
e100_set_duplex(dev, ecmd->duplex == DUPLEX_HALF ? half : full);
e100_set_speed(dev, ecmd->speed == SPEED_10 ? 10: 100);
}
-
+ //Honor ethtool phy address parameter, which was simply
discarded before this.
+ if (ecmd->phy_address <= 31)
+ mdio_phy_addr = ecmd->phy_address;
+ else if (ecmd->phy_address == 32)
+ return -ENODEV;
return 0;
}
