#pragma once
#include <QEvent>


namespace onescan {
	namespace event {
		//////////////////////////////////////////////////////////////////////////
		// MessageEvent
		// 메세지 노출 관련 이벤트를 정의 함.
		// Qt event system을 사용하기 위한, custom event example
		//////////////////////////////////////////////////////////////////////////

		enum class MessageType;

		class MessageEvent : public QEvent
		{
		public:
			MessageEvent(const MessageType mtype) : QEvent(MessageEvent::type()), m_message_type(mtype)
			{}
			virtual ~MessageEvent() = default;

			static QEvent::Type type()
			{
				if (messageEvent == QEvent::None)
				{
					int generatedType = QEvent::registerEventType(static_cast<int>(QEvent::User) + 1000);
					messageEvent = static_cast<QEvent::Type>(generatedType);
				}
				return messageEvent;
			}

			void setMessageType(const MessageType mtype) { m_message_type = mtype; }
			const MessageType& messageType() const { return m_message_type; }

		private:
			MessageType m_message_type;
			static QEvent::Type messageEvent;
		};

		enum class MessageType
		{
			TRY_CONNECT,
			CONNECTION_FAILED,
			READY_TO_DEVICE,
			READY_TO_SCAN,
			REQUEST_STOP_SCAN,
			A_SCAN_FINISHED,
			TOOTH_MARKER_SELECTED,
			TOOTH_MARKER_GUIDE,
			NEED_CALIBARATION,
			SCANGROUP_EXPORT_COMPLETE,
		};
	}
}