// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once
#if WITH_EDITOR
#include "Misc/OutputDevice.h"
#include "Logging/MessageLog.h"

class FOWLMessageGatherer : public FOutputDevice
{
public:
	FOWLMessageGatherer();
	~FOWLMessageGatherer() = default;

	void StartGathering();
	void StopGathering();

	virtual void Serialize(const TCHAR* V, ELogVerbosity::Type Verbosity, const class FName& Category) override;
	virtual void Flush() override;

	void OpenIfErrors() const;
	void OpenIfWarnings() const;
	void OpenLog() const;

private:
	TUniquePtr<FMessageLog> ExecutorLog;
	bool bErrorRecorded = false;
	bool bWarningRecorded = false;
};
#endif

