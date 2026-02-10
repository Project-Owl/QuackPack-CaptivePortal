/**
 * @file CaptivePortal.h
 * @brief This file is internal to CDP and provides the web server functionality of the default Captive Portal.
 *
 * The implementation is conditioned by the `CDPCFG_WIFI_NONE` flag which may be
 * defined in `cdpcfh.h` to disable WiFi.
 * @version
 * @date 2025-08-6
 *
 * @copyright
 */

#pragma once

#include <Arduino.h>
#include <Update.h>
#include <ESPAsyncWebServer.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <DNSServer.h>
#include <ESPmDNS.h>
#include <CDP.h>

#include "./portalPages/index.h"
#include "./portalPages/wifiCredentials.h"
#include "./portalPages/controlPanel.h"
#include "./portalPages/cdpHome.h"
#include "./portalPages/papaHome.h"
#include "./QuackPack.h"

#define AP_SCAN_INTERVAL_MS 10
class CaptivePortal : public QuackPack {
  public:
    CaptivePortal(Duck<DuckWifi, DuckLoRa>& duck): webServer(CDPCFG_WEB_PORT), events("/events") {}

    /**
     * @brief Setup WiFi access point.
     *
     * @param accessPoint a string representing the access point. Default to
     * "🆘 DUCK EMERGENCY PORTAL"
     *
     * @returns DUCK_ERROR_NONE if successful, an error code otherwise.
     */
    int setupAccessPoint(const char* ap = "🆘 DUCK EMERGENCY PORTAL");

    /**
     * @brief Setup DNS for Captive Portal
     *
     * @returns DUCK_ERROR_NONE if successful, an error code otherwise.
     */
    int setupDns();
    /**
     * @brief Set up the WebServer.
     *
     * The WebServer is used to communicate with the Duck over ad-hoc WiFi
     * connection.
     *
     * @param createCaptivePortal set to true if Captive WiFi connection is
     * needed. Defaults to false
     * @param html A string representing custom HTML code used for the portal.
     * Default is an empty string Default portal web page is used if the string is
     * empty
     */
    int setupWebServer();

    void launch() override {
      this->setupAccessPoint();
      this->setupDns();
      this->setupWebServer();
    }
    // void init(Duck& duck) override {
    //   this->duck = &duck;
    // }
    const char* getName() const override { return "captivePortal"; }

  private:

    CaptivePortal(CaptivePortal const&) = delete;
    CaptivePortal& operator=(CaptivePortal const&) = delete;
    IPAddress apIP{CDPCFG_AP_IP1, CDPCFG_AP_IP2, CDPCFG_AP_IP3, CDPCFG_AP_IP4};
    DNSServer dnsServer;
    const char* DNS = "duck";
    const byte DNS_PORT = 53;
    int port = CDPCFG_WEB_PORT;

    AsyncWebServer webServer;
    AsyncEventSource events;

    std::array<byte,8> deviceId;

    std::string portal = "";
    std::string duckSession;
    Duck<DuckWifi, DuckLoRa>* duck;
};
