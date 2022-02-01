#pragma once
#include "afv_native_export.h"
#include <string>
#include <map>
#include <vector>

namespace afv_native::api {
    class atcClient {

        public:
            AFV_NATIVE_EXPORT atcClient(std::string clientName, std::string resourcePath = "");
            AFV_NATIVE_EXPORT ~atcClient();

            AFV_NATIVE_EXPORT bool IsInitialized();

            AFV_NATIVE_EXPORT void SetCredentials(std::string username, std::string password);

            AFV_NATIVE_EXPORT void SetCallsign(std::string callsign);
            AFV_NATIVE_EXPORT void SetClientPosition(double lat, double lon, double amslm, double aglm);

            AFV_NATIVE_EXPORT bool IsVoiceConnected();
            AFV_NATIVE_EXPORT bool IsAPIConnected();

            AFV_NATIVE_EXPORT bool Connect();
            AFV_NATIVE_EXPORT void Disconnect();

            AFV_NATIVE_EXPORT void SetAudioApi(unsigned int api);
            AFV_NATIVE_EXPORT std::map<unsigned int, std::string> GetAudioApis();

            AFV_NATIVE_EXPORT void SetAudioInputDevice(std::string inputDevice);
            AFV_NATIVE_EXPORT std::vector<std::string> GetAudioInputDevices(unsigned int mAudioApi);
            AFV_NATIVE_EXPORT void SetAudioOutputDevice(std::string outputDevice);
            AFV_NATIVE_EXPORT std::vector<std::string> GetAudioOutputDevices(unsigned int mAudioApi);

            AFV_NATIVE_EXPORT double GetInputPeak() const;
            AFV_NATIVE_EXPORT double GetInputVu() const;

            AFV_NATIVE_EXPORT void SetEnableInputFilters(bool enableInputFilters);
            AFV_NATIVE_EXPORT void SetEnableOutputEffects(bool enableEffects);
            AFV_NATIVE_EXPORT bool GetEnableInputFilters() const;

            AFV_NATIVE_EXPORT void StartAudio();
            AFV_NATIVE_EXPORT void StopAudio();

            AFV_NATIVE_EXPORT void SetTx(unsigned int freq, bool active);
            AFV_NATIVE_EXPORT void SetRx(unsigned int freq, bool active);

            AFV_NATIVE_EXPORT void SetPtt(bool pttState);

            AFV_NATIVE_EXPORT std::string LastTransmitOnFreq(unsigned int freq);

            AFV_NATIVE_EXPORT void AddFrequency(unsigned int freq);
    };
}